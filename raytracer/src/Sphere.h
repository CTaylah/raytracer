#pragma once

#include "Ray.h"
#include "HitData.h"

class Sphere
{
public:
    Sphere(float radius, Vec3 center) : m_radius(radius), m_center(center) {}
    float GetRadius() const { return m_radius; };
    Vec3 GetCenter() const { return m_center; };

    HitData Hit(const Ray& ray);
     
private:
    float m_radius;
    Vec3 m_center;
    Vec3 m_color;

};