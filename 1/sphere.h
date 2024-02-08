//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENT_SPHERE_H
#define ASSIGNMENT_SPHERE_H

#include "object3d.h"
#include "hit.h"
#include "ray.h"
class Sphere: public Object3D
{
public:
    Sphere(const Vec3f& center,float radius,Material *material);

    bool intersect(const Ray &r, Hit &h, float tmin) override;
private:
    Vec3f _center;
    float _radius;
    constexpr static float _error = 1e-4;
};


#endif //ASSIGNMENT_SPHERE_H
