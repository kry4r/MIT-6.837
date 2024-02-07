//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENT_CAMERA_H
#define ASSIGNMENT_CAMERA_H

#include "vectors.h"
#include "ray.h"

class Camera {
public:
    virtual Ray generateRay(Vec2f point) = 0;
    virtual float getTMin() const = 0;

    virtual ~Camera() = default;
};

class OrthographicCamera : public Camera {
    Vec3f _center, _direction, _up, _horizontal;
    float _size;

public:
    OrthographicCamera(const Vec3f &center, const Vec3f &direction, const Vec3f &up, float size);

    Ray generateRay(Vec2f point) override;
    float getTMin() const override;

    ~OrthographicCamera() override = default;
};

#endif //ASSIGNMENT_CAMERA_H
