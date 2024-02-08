

#ifndef ASSIGNMENTS_OBJECT3D_H
#define ASSIGNMENTS_OBJECT3D_H

#include "ray.h"
#include "hit.h"

class Object3D {
protected:
    Material *_m = nullptr;

public:
    virtual bool intersect(const Ray &r, Hit &h, float tmin) = 0;
};

#endif //ASSIGNMENTS_OBJECT3D_H
