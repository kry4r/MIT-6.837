//
// Created by Nidhogg on 2024/2/7.
//

#include "sphere.h"

Sphere::Sphere(const Vec3f& center,float radius,Material* material)
{
    this->_radius = radius;
    this->_center = center;
    _m = material;
}

bool Sphere::intersect(const Ray &r, Hit &h, float tmin) {
    const auto &origin = r.getOrigin();
    auto dorigin = origin- _center;
    auto squareorigin = dorigin.Dot3(dorigin);
    auto squareraidus = _radius * _radius;
    auto dfootpointtoorigin = -dorigin.Dot3(r.getDirection());
    auto squredistray = squareorigin-dfootpointtoorigin*dfootpointtoorigin;
    if(squredistray > squareraidus) return false;
    auto squaredisintersectiontofootpoint = squareraidus-squredistray;
    auto dintersectontoorigin_1 = dfootpointtoorigin+sqrt(squaredisintersectiontofootpoint);
    auto dintersectontoorigin_2 = dfootpointtoorigin-sqrt(squaredisintersectiontofootpoint);
    auto intersectiontorigin_min = std::min(dintersectontoorigin_1,dintersectontoorigin_2);
    auto intersectiontorigin_max = std::max(dintersectontoorigin_2,dintersectontoorigin_1);
    float t;
    if(intersectiontorigin_min>= tmin) t=intersectiontorigin_min;
    else if(intersectiontorigin_max >= tmin) t=intersectiontorigin_max;
    else return false;
    h=Hit(t,_m);
    return true;
}