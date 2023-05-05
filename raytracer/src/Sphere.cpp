#include "Sphere.h"

HitData Sphere::Hit(const Ray& ray)
{
   
    Vec3 direction = ray.GetDirection();
    Vec3 origin = ray.GetOrigin();

    float a = Dot(direction, direction);
    float b = 2 * Dot(direction, origin - m_center);
    float c = Dot(origin - m_center, origin - m_center) - m_radius * m_radius;
    
    float discriminant= b * b - 4 * a * c;

    if(discriminant < 0) 
        return HitData(false, Vec3(0.0f,0.0f,0.0f));

    float t = ((-b - std::sqrt(discriminant)) / (2.0f * a));

    if(t < 0.0f) 
        return HitData(false, Vec3(0.0f,0.0f,0.0f));

    return HitData(true, ray.At(t));

 
}