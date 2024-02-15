//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENT_SPHERE_H
#define ASSIGNMENT_SPHERE_H

#include "object3d.h"
#include "hit.h"
#include "vectors.h"

class Sphere : public Object3D {
    Vec3f _center;
    float _radius;

    void getXYZBySphereCoord(float theta, float phi, float &x, float &y, float &z);

public:
    Sphere(const Vec3f &center, float radius, Material *material);
    bool intersect(const Ray &r, Hit &h, float tmin) override;
    void paint() override;

    void insertIntoGrid(Grid *g, Matrix *m) override;
};

#endif //ASSIGNMENTS_SPHERE_H
