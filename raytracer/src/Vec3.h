#pragma once

#include "Util.h"

#include <cmath>
#include <iostream>

struct Vec3
{
    Vec3() : x(0.0f), y(0.0f), z(0.0f) {};
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {};

    float x, y, z;

    float LengthSquared() const
    {
        return x * x + y * y + z * z;
    }

    float Length() const
    {
        return std::sqrt(LengthSquared());
    }

    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    Vec3& operator+=(const Vec3& other)
    {
        x += other.x;
        y += other.y; 
        z += other.z;

        return *this;
    }
    Vec3& operator*=(const Vec3& other) 
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;

        return *this;
    }

    Vec3& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;

        return *this;
    } 

    Vec3& operator/=(float scalar)
    {
        return *this *= 1/scalar;
    }    

    inline static Vec3 Random()
    {
        return Vec3(Util::RandomFloat(), Util::RandomFloat(), Util::RandomFloat());
    }

};

inline Vec3 operator*(const Vec3& vector, const float scalar)
{
    return Vec3(vector.x * scalar,vector.y * scalar, vector.z  * scalar);
}

inline Vec3 operator*(const float scalar, const Vec3& vector)

{
    return Vec3(vector.x * scalar,vector.y * scalar, vector.z  * scalar);
}

inline Vec3 operator/(const Vec3& vector, const float scalar )
{
    return vector * (1/scalar);
}

inline Vec3 operator+(const Vec3& vector1, const Vec3& vector2)
{
    return Vec3(vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z);
}

inline Vec3 operator-(const Vec3& vector1, const Vec3& vector2)
{
    return Vec3(vector1.x - vector2.x, vector1.y - vector2.y, vector1.z - vector2.z);
}

inline std::ostream& operator<<(std::ostream& os, const Vec3& vec)
{
    os << vec.x << " " << vec.y << " " << vec.z;
    return os;
}

inline float Dot(const Vec3& vector1, const Vec3& vector2)
{
   return((vector1.x * vector2.x) + (vector1.y * vector2.y) + (vector1.z * vector2.z));
}

inline Vec3 Cross(const Vec3& vector1, const Vec3& vector2)
{
    float x = (vector1.y * vector2.z) - (vector1.z * vector2.y);
    float y = (vector1.z * vector2.x) - (vector1.x * vector2.z);
    float z = (vector1.x * vector2.y) - (vector1.y * vector2.x);
    return Vec3(x, y, z);
}

inline Vec3 UnitVector(const Vec3& vector)
{
    return vector / vector.Length();
}

