#pragma once

#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>

#include <random>

namespace Util{

    const float infinity = std::numeric_limits<float>::infinity();
    const double pi = 3.1415926535897932385;

    inline double DegreesToRadians(double degrees) {
        return degrees * pi / 180.0;
    }

    //By default generates from zero to one
    inline float RandomFloat() {
       static std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
       static std::mt19937 generator;
       return distribution(generator);
    }

    inline float RandomFloat(float min, float max) {
       static std::mt19937 generator(std::random_device{}());
       std::uniform_real_distribution<float> distribution(min, max);
       return distribution(generator);
    }


    inline double clamp(float x, float min, float max) {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }
}