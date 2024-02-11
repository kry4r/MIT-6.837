//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENT_OBJECT3D_H
#define ASSIGNMENT_OBJECT3D_H

#include <GL/gl.h>

#include "ray.h"
#include "hit.h"
#include "material.h"

class Object3D {
protected:
    Material *_m = nullptr;

public:
    virtual bool intersect(const Ray &r, Hit &h, float tmin) = 0;
    virtual void paint() = 0;
};

#endif //ASSIGNMENTS_OBJECT3D_H
