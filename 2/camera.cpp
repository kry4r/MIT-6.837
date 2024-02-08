//
// Created by Nidhogg on 2024/2/7.
//

#include "camera.h"

#include <limits>

Ray OrthographicCamera::generateRay(Vec2f point) {
    auto origin = _center + (point.x() - 0.5) * _size * _horizontal + (point.y() - 0.5) * _size * _up;
    return Ray(origin, _direction);
}

float OrthographicCamera::getTMin() const {
    return std::numeric_limits<float>::lowest();
}

OrthographicCamera::OrthographicCamera(const Vec3f &center, const Vec3f &direction, const Vec3f &up, float size) {
    _center = center;
    _direction = direction;
    _direction.Normalize();
    Vec3f::Cross3(_horizontal, direction, up);
    _horizontal.Normalize();
    Vec3f::Cross3(_up, _horizontal, direction);
    _up.Normalize();
    _size = size;
}

PerspectiveCamera::PerspectiveCamera(const Vec3f &center, const Vec3f &direction, const Vec3f &up, float angleRadians) {
    _center = center;
    _direction = direction;
    _direction.Normalize();
    // 计算相机的水平方向
    Vec3f::Cross3(_horizontal, direction, up);
    _horizontal.Normalize();
    // 计算相机的垂直方向
    Vec3f::Cross3(_up, _horizontal, direction);
    _up.Normalize();
    // 计算相机的视野大小
    _size = tanf(angleRadians / 2.f) * 2.f;
}

Ray PerspectiveCamera::generateRay(Vec2f point) {
    // 计算射线方向
    Vec3f rayDir = _direction + (point.x() - 0.5) * _size * _horizontal + (point.y() - 0.5) * _size * _up;
    rayDir.Normalize();
    return Ray(_center, rayDir);
}

float PerspectiveCamera::getTMin() const {
    // 返回最小的t值
    return 0;
}
