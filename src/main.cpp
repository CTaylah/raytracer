#include "Vec3.h"

#include <iostream>

int main() {
    const int image_width = 256, image_height = 256;

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n"; 

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            //Colors are normalized
            auto r = float(i) / (image_width - 1);
            auto g = float(j) / (image_height - 1);
            auto b = 0.25;

            Vec3 color(r,g,b);
            WriteColor(std::cout, color);
        }
    }

    return 0;
}
