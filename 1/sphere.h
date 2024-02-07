//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENT_SPHERE_H
#define ASSIGNMENT_SPHERE_H

#include "object3d.h"
class sphere: public Object3D
{
public:
    sphere();

    virtual bool intersect(const Ray &r, Hit &h, float tmin) override;
};


#endif //ASSIGNMENT_SPHERE_H
