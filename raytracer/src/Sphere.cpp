#include "Sphere.h"

HitData Sphere::Hit(const Ray& ray, float tMin, float tMax)
{
   
    Vec3 direction = ray.GetDirection();
    Vec3 origin = ray.GetOrigin();

    float a = Dot(direction, direction);
    float b = 2 * Dot(direction, origin - m_center);
    float c = Dot(origin - m_center, origin - m_center) - m_radius * m_radius;
    
    float discriminant= b * b - 4 * a * c;

    if(discriminant < 0) 
        return HitData(false);

    float sqrtDiscriminat = std::sqrt(discriminant);
    

    float t = ((-b - sqrtDiscriminat) / (2.0f * a));

    if(t < tMin || t > tMax){
        t = ((-b + sqrtDiscriminat) / (2.0f * a));
        if(t < tMin || t > tMax)
            return HitData(false);
    }

    Vec3 point = ray.At(t);
    Vec3 normal = UnitVector(point - m_center); 
    return HitData(true, ray, t, normal);
 
}

HitData SphereList::Hit(const Ray& ray, float tMin, float tMax) const
{
    float closestHit = tMax; // t value of the closest hit.
    
    HitData data(false);

    for(const auto& sphere : m_sphereList)
    {
        HitData tempData = sphere->Hit(ray, tMin, closestHit);
        if(tempData.hit)
        {
            closestHit = tempData.distance;
            data = tempData;
        }
    }
    return data;
}