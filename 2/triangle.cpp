//
// Created by Nidhogg on 2024/2/8.
//

#include "triangle.h"

Triangle::Triangle(const Vec3f &v0, const Vec3f &v1, const Vec3f &v2, Material *m) : _plane(v0, v1, v2, m) {
    _v0 = v0;
    _v1 = v1;
    _v2 = v2;
    _m = m;

    Vec3f v0v1 = v1 - v0, v1v2 = v2 - v1;
    Vec3f::Cross3(_norm, v0v1, v1v2);
    _norm.Normalize();
}

bool Triangle::intersect(const Ray &r, Hit &h, float tmin) {
    Vec3f c,edge,pv,intersection;
    Hit hit;
    if(_plane, intersect(r,hit,tmin))
    {
        if(hit.getT() >= tmin)
        {
            intersection = hit.getIntersectionPoint();
            edge = _v0 - _v1;
            pv = intersection - _v0;
            Vec3f::Cross3(c,pv,edge);
            if(c.Dot3(_norm)<0) return false;
            edge = _v1 - _v2;
            pv = intersection - _v1;
            Vec3f::Cross3(c, pv, edge);
            if (c.Dot3(_norm) < 0) return false;
            edge = _v2 - _v0;
            pv = intersection - _v2;
            Vec3f::Cross3(c, pv, edge);
            if (c.Dot3(_norm) < 0) return false;
            h = hit;
            return true;
        }
        else return false;
    }
    else return false;
}