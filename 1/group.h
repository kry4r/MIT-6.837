//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENT_GROUP_H
#define ASSIGNMENT_GROUP_H
#include "object3d.h"
#include <vector>

class Group :public Object3D{
public:
    Group(int nobj);
    void addObject(int index, Object3D *obj);
    bool intersect(const Ray &r, Hit &h, float tmin) override;
private:
    std::vector<Object3D*> _objs;
    unsigned long _nobj;
};


#endif //ASSIGNMENT_GROUP_H
