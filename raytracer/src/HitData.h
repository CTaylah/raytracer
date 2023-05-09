#pragma once

#include "Vec3.h"


struct Material
{
    Material(const Vec3& albedo) : albedo(albedo) {}
    Material() : albedo(0.5f,0.5f,0.5f) {}
    Vec3 albedo;
};


struct HitData
{
    //outawardNormal:
    HitData(bool hit, const Ray& ray, float t, const Vec3& outwardNormal, Material material) 
        : hit(hit), material(material) 
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
    Material material;
};


