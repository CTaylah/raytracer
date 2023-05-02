#pragma once

#include <cmath>
#include <iostream>

struct Vec3
{
    Vec3() : x(0.0f), y(0.0f), z(0.0f) {};
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {};

    float x, y, z;

    inline float LengthSquared()
    {
        return x * x + y * y + z * z;
    }

    inline float Length()
    {
        return std::sqrt(LengthSquared());
    }

    inline Vec3 operator+(const Vec3& other)
    {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    inline Vec3& operator+=(const Vec3& other)
    {
        x += other.x;
        y += other.y; 
        z += other.z;

        return *this;
    }

    inline Vec3 operator-(const Vec3& other)
    {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    inline Vec3 operator*(const Vec3& other)
    {
        return Vec3(x * other.x, y * other.y, z * other.z);
    }

    inline Vec3& operator*=(const Vec3& other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;

        return *this;
    }

    inline Vec3 operator*(float scalar)
    {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    inline Vec3& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;

        return *this;
    } 

    inline Vec3 operator/(float scalar)
    {
        return Vec3(x / scalar, y / scalar, z / scalar);
    }

    inline Vec3& operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec3& vec)
    {
        os << vec.x << " " << vec.y << " " << vec.z;
        return os;
    }

};

//Assumes color is normalized then writes 0-255 rgb values
void WriteColor(std::ostream& out, Vec3 pixelColor)
{
    out << static_cast<int>(255.999 * pixelColor.x) << ' '
        << static_cast<int>(255.999 * pixelColor.y) << ' '
        << static_cast<int>(255.999 * pixelColor.z) << '\n';
}