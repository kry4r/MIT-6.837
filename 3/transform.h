//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENTS_TRANSFORM_H
#define ASSIGNMENTS_TRANSFORM_H

#include "object3d.h"
#include "matrix.h"

class Transform : public Object3D {
    Matrix _mat, _invMat, _invTpMat;
    Object3D *_object;

public:
    Transform(const Matrix &mat, Object3D *object);

    bool intersect(const Ray &r, Hit &h, float tmin) override;
    void paint() override;
};

#endif //ASSIGNMENTS_TRANSFORM_H
