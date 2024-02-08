//
// Created by Nidhogg on 2024/2/8.
//

#ifndef ASSIGNMENT_PLANE_H
#define ASSIGNMENT_PLANE_H

#include "object3d.h"


class Plane : public Object3D{
public:
    Plane(Vec3f &normal, float d, Material *m);
    Plane(const Vec3f &v0, const Vec3f &v1, const Vec3f &v2, Material *m);

    bool intersect(const Ray &r, Hit &h, float tmin) override;
private:
    Vec3f _normal;
    float _offset;
};


#endif //ASSIGNMENT_PLANE_H
