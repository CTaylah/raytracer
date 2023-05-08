#pragma once

#include "Vec3.h"


struct HitData
{
    //outawardNormal:
    HitData(bool hit, const Ray& ray, float t, const Vec3& outwardNormal) 
        : hit(hit) 
    {
        point = ray.At(t); 
        distance = t;
        frontFace = Dot(ray.GetDirection(), outwardNormal) < 0;
        if(frontFace)
            normal = outwardNormal;
        else
            normal = -outwardNormal;
        
        
    }
    HitData(bool hit): hit(hit) {}
    HitData() = default;

    bool hit;
    Vec3 point;
    float distance;
    bool frontFace;
    
    Vec3 normal;
};


