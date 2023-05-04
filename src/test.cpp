#include "Vec3.h"

#include <iostream>

int main() {

    Vec3 lowerLeft(-1.777779f, -1.0f, -1.0f);
    Vec3 u(0.0f,0.0f,0.0f);
    Vec3 v(0.0f, 2.0f, 0.0f);
    Vec3 origin(0.0f, 0.0f, 0.0f);

    Vec3 direction = lowerLeft + u;

    std::cout << direction << std::endl;
    return 0;
}