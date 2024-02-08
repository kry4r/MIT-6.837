//
// Created by Nidhogg on 2024/2/7.
//

#include "group.h"
#include "limits"

bool Group::intersect(const Ray &r, Hit &h, float tmin) {
    h=Hit(std::numeric_limits<float>::max(), nullptr,Vec3f());
    bool success  = false;
    for(auto obj :_objs)
    {
        Hit currentHit;
        if(obj->intersect(r,currentHit,tmin))
        {
            success = true;
            if(currentHit.getT() < h.getT()) h =currentHit;
        }
    }
    return success;
}

Group::Group(int nobj) {
    assert(_nobj>=0);
    _nobj = nobj;
    _objs.resize(_nobj);
}

void Group::addObject(int index, Object3D *obj){
    assert(index < _nobj);
    _objs[index] = obj;
}