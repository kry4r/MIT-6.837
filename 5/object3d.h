//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENT_OBJECT3D_H
#define ASSIGNMENT_OBJECT3D_H

#include <memory>

#include <GL/gl.h>

#include "vectors.h"
#include "matrix.h"

class Grid;
class Ray;
class Hit;
class Material;
class BoundingBox;

enum ObjectType {
    SphereObject, PlaneObject, TriangleObject, GridObject, GroupObject
};

class Object3D {
protected:
    Material *_m = nullptr;
    std::shared_ptr<BoundingBox> _bb;

    ObjectType _type;

public:
    virtual bool intersect(const Ray &r, Hit &h, float tmin) = 0;
    virtual void paint() = 0;

    ObjectType getObjectType() const { return _type; }
    std::shared_ptr<BoundingBox> getBoundingBox() const { return _bb; }

    virtual void insertIntoGrid(Grid *g, Matrix *m);
};

#endif //ASSIGNMENTS_OBJECT3D_H
