//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENT_RAYTRACER_H
#define ASSIGNMENT_RAYTRACER_H

#include <memory>

#include "scene_parser.h"
#include "image.h"
#include "camera.h"
#include "group.h"
#include "hit.h"
#include "material.h"
#include "commandLineArgs.h"
#include "raytree.h"

class RayTracer {
    std::shared_ptr<SceneParser> _sceneParser;
    std::shared_ptr<CommandLineArgumentParser> _cmdParser;
    Vec3f _bgColor;
    Group *_group;
    unsigned long _nLights;
    std::vector<Light*> _lights;
    Vec3f _ambient;

    Vec3f _mirrorDirection(const Vec3f &normal, const Vec3f &incoming) const;
    bool _transmittedDirection(const Vec3f &normal, const Vec3f &incoming, float index_i, float index_t,
                               Vec3f &transmittedDir) const;

public:
    RayTracer(const std::shared_ptr<SceneParser> &scParser, const shared_ptr<CommandLineArgumentParser> &cmdlParser);

    Vec3f traceRay(Ray &ray, float tmin, int bounces, float weight, float indexOfRefraction, Hit &hit) const;
};

#endif //ASSIGNMENTS_RAYTRACER_H
