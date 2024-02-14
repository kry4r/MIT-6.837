//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENT_RAYTRACER_H
#define ASSIGNMENT_RAYTRACER_H

#include <memory>

#include "scene_parser.h"
#include "commandLineArgs.h"
#include "ray.h"
#include "hit.h"
#include "group.h"
#include "light.h"
#include "grid.h"

class RayTracer {
    std::shared_ptr<SceneParser> _sceneParser;
    std::shared_ptr<CommandLineArgumentParser> _cmdlParser;

    Vec3f _bgColor;
    Group *_group;
    unsigned long _nLights;
    std::vector<Light*> _lights;
    Vec3f _ambient;

    Vec3f _mirrorDirection(const Vec3f &normal, const Vec3f &incoming) const;
    bool _transmittedDirection(const Vec3f &normal, const Vec3f &incoming, float index_i, float index_t,
                               Vec3f &transmittedDir) const;

    std::shared_ptr<Grid> _grid;

    bool _castRay(Ray &ray, Hit &hit, float tmin) const;

public:
    RayTracer(const std::shared_ptr<SceneParser> &scParser, const shared_ptr<CommandLineArgumentParser> &cmdlParser);

    Vec3f traceRay(Ray &ray, float tmin, int bounces, float weight, float indexOfRefraction, Hit &hit) const;

    Grid *getGrid() { return _grid.get(); }

    BoundingBox *getBoundingBox() { return _group->getBoundingBox().get(); };
};

#endif //ASSIGNMENTS_RAYTRACER_H
