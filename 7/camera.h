//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENT_CAMERA_H
#define ASSIGNMENT_CAMERA_H

#include <GL/gl.h>
#include <GL/glu.h>

#include "vectors.h"
#include "ray.h"

class Camera {
public:
    virtual Ray generateRay(Vec2f point) = 0;
    virtual float getTMin() const = 0;

    virtual void glInit(int w, int h) = 0;
    virtual void glPlaceCamera(void) = 0;
    virtual void dollyCamera(float dist) = 0;
    virtual void truckCamera(float dx, float dy) = 0;
    virtual void rotateCamera(float rx, float ry) = 0;

    virtual ~Camera() = default;
};

class OrthographicCamera : public Camera {
    Vec3f _center, _direction, _up, _horizontal, _rawUp;
    float _size;

public:
    OrthographicCamera(const Vec3f &center, const Vec3f &direction, const Vec3f &up, float size);

    Ray generateRay(Vec2f point) override;
    float getTMin() const override;

    void glInit(int w, int h) override;
    void glPlaceCamera() override;
    void dollyCamera(float dist) override;
    void truckCamera(float dx, float dy) override;
    void rotateCamera(float rx, float ry) override;
};

class PerspectiveCamera : public Camera {
    Vec3f _center, _direction, _up, _horizontal, _rawUp;
    float _size, _angle;

public:
    PerspectiveCamera(const Vec3f &center, const Vec3f &direction, const Vec3f &up, float angleRadians);

    Ray generateRay(Vec2f point) override;
    float getTMin() const override;

    void glInit(int w, int h) override;
    void glPlaceCamera() override;
    void dollyCamera(float dist) override;
    void truckCamera(float dx, float dy) override;
    void rotateCamera(float rx, float ry) override;
};


#endif //ASSIGNMENTS_CAMERA_H
