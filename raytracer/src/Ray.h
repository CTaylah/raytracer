#pragma once

#include "Vec3.h"

//Point on ray = Origin + t * Direction


class Ray
{
    public:
        Ray() {}
        Ray(Vec3 origin, Vec3 direction) : m_origin(origin), m_direction(direction) {}

        Vec3 At(float t) const { return  (m_direction * t) + m_origin;}

        Vec3 GetOrigin() const { return m_origin; }
        Vec3 GetDirection() const { return m_direction; }

    private:
        Vec3 m_origin;
        Vec3 m_direction;
};