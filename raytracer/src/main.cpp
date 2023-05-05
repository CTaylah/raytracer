#include "Vec3.h"
#include "Sphere.h"

#include <iostream>


void WriteColor(std::ostream& out, Vec3 pixelColor)
{
    out << static_cast<int>(255.999 * pixelColor.x) << ' '
        << static_cast<int>(255.999 * pixelColor.y) << ' '
        << static_cast<int>(255.999 * pixelColor.z) << '\n';
}

Sphere sphere(0.25f, Vec3(0.0f,0.0f, -1.0f));

Vec3 RayColor(const Ray& r){
    Vec3 unitDirection = UnitVector(r.GetDirection());
    float t = 0.5f * (unitDirection.y + 1.0f);

    HitData hitData = sphere.Hit(r); 

    if(hitData.hit) {
        Vec3 normal = UnitVector(hitData.point - Vec3(0.0f, 0.0f, -1.0f));
        Vec3 color = 0.3f * Vec3(normal.x + 1, normal.y + 1, normal.z + 1);
        return color;
    }
    return (1.0f - t) * Vec3(1.0f, 1.0f, 1.0f) + t * Vec3(0.5f, 0.7f, 1.0f);
}

int main() {
    const float aspectRatio= 16.0f / 9.0f;
    const int image_width = 400; 
    const int image_height = static_cast<int>(image_width/ aspectRatio);


    float viewportHeight = 2.0f, viewportWidth = aspectRatio * viewportHeight;
    float focalLength = 1.0f;

    Vec3 cameraPosition;
    Vec3 horizontal(viewportWidth, 0.0f, 0.0f);
    Vec3 vertical (0.0f, viewportHeight, 0.0f);

    Vec3 lowerLeft = cameraPosition - (horizontal/2.0f) - (vertical/2) - Vec3(0,0,focalLength);



    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n"; 

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            //Colors are normalized
            float u = float(i) / (image_width - 1);
            float v = float(j) / (image_height - 1);

            Ray ray(cameraPosition, lowerLeft + u * horizontal + v * vertical - cameraPosition);
            Vec3 pixelColor = RayColor(ray);
            WriteColor(std::cout, pixelColor);
        }
    }
    std::cerr << "\nDone\n";
    return 0;
}
