//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENT_PLANE_H
#define ASSIGNMENT_PLANE_H

#include "object3d.h"

class Plane : public Object3D {
    Vec3f _normal;
    float _offset;

public:
    Plane(const Vec3f &normal, float offset, Material *m);
    Plane(const Vec3f &v0, const Vec3f &v1, const Vec3f &v2, Material *m);

    bool intersect(const Ray &r, Hit &h, float tmin) override;
    void paint() override;

    void insertIntoGrid(Grid *g, Matrix *m) override;
};

#endif //ASSIGNMENTS_PLANE_H
