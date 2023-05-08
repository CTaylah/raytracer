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

    inline float RandomFloat() {
       static std::mt19937 generator(std::random_device{}());
       std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
       return distribution(generator);
    }



    inline float clamp(float x, float min, float max) {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }
}