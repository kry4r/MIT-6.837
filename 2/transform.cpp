//
// Created by Nidhogg on 2024/2/8.
//

#include "transform.h"

Transform::Transform(Matrix &m, Object3D *o) {
    _mat = m;
    _invMat = _mat;
    int r = _invMat.Inverse();
    assert(r);
    _invTpMat = _invMat;
    _invTpMat.Transpose();
    _obj = o;
}

bool Transform::intersect(const Ray &r, Hit &h, float tmin) {
    Vec4f hRayDir(r.getDirection(), 0.f);
    Vec4f hTransformedRayDir = _invMat *hRayDir;
    Vec3f transformedRayDir = Vec3f(hTransformedRayDir.x(),hTransformedRayDir.y(),hTransformedRayDir.z());
    float transformedRayDirLength = transformedRayDir.Length();
    transformedRayDir.Normalize();
    // transform ray origin from world space to object space
    Vec4f hRayOrigin(r.getOrigin(), 1.f);
    Vec4f hTransformedRayOrigin = _invMat * hRayOrigin;
    hTransformedRayOrigin.DivideByW();
    Vec3f transformedRayOrigin = hTransformedRayOrigin.xyz();

    Ray transformedRay(transformedRayOrigin, transformedRayDir);
    Hit osHit;
    if (_obj->intersect(transformedRay, osHit, tmin)) {
        // transform normal from object space to world space
        auto osNorm = osHit.getNormal();
        auto hOsNorm = Vec4f(osNorm, 0.f);
        auto hWsNorm = _invTpMat * hOsNorm;
        auto wsNorm = hWsNorm.xyz();
        wsNorm.Normalize();
        // transform depth from object space to world space
        float osT = osHit.getT();
        float wsT = osT / transformedRayDirLength;
        h = Hit(wsT, osHit.getMaterial(), wsNorm);
        return true;
    } else {
        return false;
    };
}