//
// Created by Nidhogg on 2024/2/8.
//

#ifndef ASSIGNMENT_TRANSFORM_H
#define ASSIGNMENT_TRANSFORM_H
#include "object3d.h"
#include "matrix.h"

class Transform : public Object3D{
public:
    Transform(Matrix &m, Object3D *o);
    bool intersect(const Ray &r, Hit &h, float tmin) override;
private:
    Object3D* _obj;
    Matrix _mat,_invMat, _invTpMat;
};


#endif //ASSIGNMENT_TRANSFORM_H
