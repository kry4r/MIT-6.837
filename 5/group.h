//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENT_GROUP_H
#define ASSIGNMENT_GROUP_H

#include <vector>

#include "object3d.h"

class Group : public Object3D {
    unsigned long _nObjects;
    std::vector<Object3D*> _objs;

public:
    explicit Group (int nObjects);

    bool intersect(const Ray &r, Hit &h, float tmin) override;
    void addObject(int index, Object3D *obj);
    void paint() override;

    void insertIntoGrid(Grid *g, Matrix *m) override;
};

#endif //ASSIGNMENTS_GROUP_H
