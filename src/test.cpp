#include "Vec3.h"

#include <iostream>

int main() {
    Vec3 vec3(1.0f, 2.0f, 3.0f);
    Vec3 vec4(1.0f, 2.0f, 3.0f);
    Vec3 vec7 = vec3 + vec4;
    

    std::cout << vec7.x << std::endl;

    return 0;
}