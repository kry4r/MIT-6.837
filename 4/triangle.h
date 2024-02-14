//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENT_TRIANGLE_H
#define ASSIGNMENT_TRIANGLE_H

#include "object3d.h"
#include "plane.h"
#include "material.h"
#include "vectors.h"

class Triangle : public Object3D {
    Vec3f _v0, _v1, _v2, _norm, _barycenter;
    class Plane _plane;

public:
    Triangle(const Vec3f &v0, const Vec3f &v1, const Vec3f &v2, Material *m);

    bool intersect(const Ray &r, Hit &h, float tmin) override;
    void paint() override;
};

#endif //ASSIGNMENTS_TRIANGLE_H
