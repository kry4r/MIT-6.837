//
// Created by Nidhogg on 2024/2/7.
//
#ifndef ASSIGNMENT_TRANSFORM_H
#define ASSIGNMENT_TRANSFORM_H

#include "object3d.h"
#include "matrix.h"

class Transform : public Object3D {
    Matrix _mat, _invMat, _invTpMat;
    Object3D *_object;

    bool _flattened = false;

public:
    Transform(const Matrix &mat, Object3D *object);

    bool intersect(const Ray &r, Hit &h, float tmin) override;
    void paint() override;

    void insertIntoGrid(Grid *g, Matrix *m) override;

    static BoundingBox TransformBoundingBox(const Object3D &object, const Matrix &m);

    void setFlattened() { _flattened = true; }

    ~Transform() override;
};

#endif //ASSIGNMENTS_TRANSFORM_H
