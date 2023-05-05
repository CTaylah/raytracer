#pragma once

#include "Vec3.h"


struct HitData
{
    HitData(bool hit, const Vec3& point) : hit(hit), point(point) {}
    bool hit;
    Vec3 point;
    //Vec3 color;
};


