//
// Created by Nidhogg on 2024/2/8.
//

#include "plane.h"
Plane::Plane(Vec3f &normal, float d, Material *m) {
    _normal = normal;
    _offset = d;
    _m = m;
}

Plane::Plane(const Vec3f &v0, const Vec3f &v1, const Vec3f &v2, Material *m) {
    Vec3f::Cross3(_normal,v0-v1,v1-v2);
    _normal.Normalize();
    _offset = _normal.Dot3(v0);
    _m = m;
}

bool Plane::intersect(const Ray &r, Hit &h, float tmin) {
    Hit hit;
    float t = (_offset - _normal.Dot3(r.getOrigin()))/_normal.Dot3((r.getDirection()));
    hit.set(t,_m,_normal,r);
    if(t>= tmin)
    {
        h = hit;
        return true;
    }
    return false;
}
