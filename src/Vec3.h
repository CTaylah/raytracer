#pragma once

#include <cmath>
#include <iostream>

struct Vec3
{
    Vec3() : x(0.0f), y(0.0f), z(0.0f) {};
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {};

    float x, y, z;

    float LengthSquared()
    {
        return x * x + y * y + z * z;
    }

    float Length()
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

};

//Assumes color is normalized then writes 0-255 rgb values
void WriteColor(std::ostream& out, Vec3 pixelColor)
{
    out << static_cast<int>(255.999 * pixelColor.x) << ' '
        << static_cast<int>(255.999 * pixelColor.y) << ' '
        << static_cast<int>(255.999 * pixelColor.z) << '\n';
}

inline Vec3 operator*(const Vec3& vector, const float scalar)
{
    return Vec3(vector.x * scalar,vector.y * scalar, vector.z  * scalar);
}

inline Vec3 operator*(const float scalar, const Vec3& vector)

{
    return Vec3(vector.x * scalar,vector.y * scalar, vector.z  * scalar);
}

inline Vec3 operator*(const Vec3& vector1, const Vec3& vector2)
{
    return Vec3(vector1.x * vector2.x, vector1.y * vector2.y, vector1.z * vector2.z);
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

std::ostream& operator<<(std::ostream& os, const Vec3& vec)
{
    os << vec.x << " " << vec.y << " " << vec.z;
    return os;
}

inline Vec3 UnitVector(Vec3 vector)
{
    return vector / vector.Length();
}

