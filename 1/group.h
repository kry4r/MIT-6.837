//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENT_GROUP_H
#define ASSIGNMENT_GROUP_H
#include "object3d.h"

class group :public Object3D{
    group();
    void addObject(int index, Object3D *obj);
};


#endif //ASSIGNMENT_GROUP_H
