

#include "raytracer.h"

#include <cmath>
#include <vector>

#include "light.h"

static float _err = 1e-3f;

RayTracer::RayTracer(const std::shared_ptr<SceneParser> &scParser, const shared_ptr<CommandLineArgumentParser> &cmdlParser) {
    _sceneParser = scParser;
    _cmdParser = cmdlParser;

    _bgColor = _sceneParser->getBackgroundColor();
    _group = _sceneParser->getGroup();
    _nLights = static_cast<unsigned long>(_sceneParser->getNumLights());
    _lights = std::vector<Light*>(_nLights);
    for (int i = 0; i < _nLights; ++i) {
        _lights[i] = _sceneParser->getLight(i);
    }
    _ambient = _sceneParser->getAmbientLight();
}

Vec3f RayTracer::traceRay(Ray &ray, float tmin, int bounces, float weight, float indexOfRefraction, Hit &hit) const {
    // stop criteria - recursion depth
    if (bounces > _cmdParser->max_bounces)
        return Vec3f(0.f, 0.f, 0.f);
    // stop criteria - small contribution
    if (weight < _cmdParser->cutoff_weight)
        return Vec3f(0.f, 0.f, 0.f);

    Vec3f color;
    if (_group->intersect(ray, hit, tmin)) {
        color = Vec3f(0.f, 0.f, 0.f);

        auto norm = hit.getNormal();
        bool isBackSide = norm.Dot3(ray.getDirection()) > 0;
        if (isBackSide) {
            if (_cmdParser->shade_back) {
                norm.Negate();
                hit.set(hit.getT(), hit.getMaterial(), norm, ray, hit.getObjectType()); // set back hit
            } else {
                return Vec3f(0.f, 0.f, 0.f);
            }
        }

        auto m = hit.getMaterial();

        // add help line
        if (bounces == 0)
            RayTree::SetMainSegment(ray, 0, hit.getT());

        color = _ambient * m->getDiffuseColor();
        auto intersection = hit.getIntersectionPoint();
        for (int i = 0; i < _nLights; ++i) {
            Vec3f dirToLight, lightColor;
            float distToLight;
            _lights[i]->getIllumination(intersection, dirToLight, lightColor, distToLight);

            // handle shadows
            if (_cmdParser->cast_shadow) {
                Ray shadowRay(intersection, dirToLight);
                Hit shadowHit;
                if (_group->intersect(shadowRay, shadowHit, _err) && shadowHit.getT() < distToLight) {
                    RayTree::AddShadowSegment(shadowRay, 0, shadowHit.getT());
                    continue;
                } else {
                    RayTree::AddShadowSegment(shadowRay, 0, distToLight);
                };
            }

            color += m->Shade(ray, hit, dirToLight, lightColor);
        }


        // handle reflection
        auto reflectColor = m->getReflectiveColor();
        if (reflectColor.Length() > _err) {
            Hit reflectHit;
            Ray reflectRay(intersection, _mirrorDirection(hit.getNormal(), ray.getDirection()));
            color += reflectColor * traceRay(reflectRay, _err, bounces + 1, weight * reflectColor.Length() / sqrtf(3),
                                             indexOfRefraction, reflectHit);
            if (bounces < _cmdParser->max_bounces)
                RayTree::AddReflectedSegment(reflectRay, 0, reflectHit.getT());
        }

        // handle refraction
        auto transparentColor = m->getReflectiveColor();
        auto materialIndexOfRefraction = isBackSide ? 1.f : m->getindexofrefraction(); // handle ray that goes out of the object
        if (transparentColor.Length() > _err) {
            Vec3f transmittedDir;
            auto transmitted = _transmittedDirection(hit.getNormal(), ray.getDirection(), indexOfRefraction,
                                                     materialIndexOfRefraction, transmittedDir);
            if (transmitted) {
                Hit refractHit;
                Ray refractRay(intersection, transmittedDir);
                color += transparentColor *
                         traceRay(refractRay, _err, bounces + 1, weight * transparentColor.Length() / sqrtf(3),
                                  materialIndexOfRefraction, refractHit);
                if (bounces < _cmdParser->max_bounces)
                    RayTree::AddTransmittedSegment(refractRay, 0, refractHit.getT());
            }
        }
    } else {
        color = _bgColor;
    }

    return color;
}

Vec3f RayTracer::_mirrorDirection(const Vec3f &normal, const Vec3f &incoming) const {
    // R = V – 2 (V · N) N
    auto reflectDir = incoming - 2 * (incoming.Dot3(normal)) * normal;
    reflectDir.Normalize();
    return reflectDir;
}

bool RayTracer::_transmittedDirection(const Vec3f &normal, const Vec3f &incoming, float index_i, float index_t,
                                      Vec3f &transmittedDir) const {
    // [ηr * (N · I) – √(1 – ηr^2 * (1 – (N · I)^2))] * N – ηr * I
    auto i = incoming;
    i.Negate();
    auto eta = index_i / index_t;
    auto cosThetaTSquare = 1.f - eta * eta * (1.f - normal.Dot3(i) * normal.Dot3(i));
    if (cosThetaTSquare < 0.f)
        return false;
    transmittedDir = (eta * (normal.Dot3(i)) - sqrtf(cosThetaTSquare)) * normal - eta * i;
    transmittedDir.Normalize();
    return true;
}