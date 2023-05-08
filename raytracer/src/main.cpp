#include "Vec3.h"
#include "Sphere.h"
#include "Util.h"
#include "Camera.h"
#include <iostream>


void WriteColor(std::ostream& out, Vec3 pixelColor, int samplesPerPixel)
{
    float r = pixelColor.x;
    float g = pixelColor.y;
    float b = pixelColor.z;

    float scale = 1.0f / samplesPerPixel;
    r *= scale;
    g *= scale;
    b *= scale;

    out << static_cast<int>(256 * Util::clamp(r, 0.0f, 0.999f)) << ' '
        << static_cast<int>(256 * Util::clamp(g, 0.0f, 0.999f)) << ' '
        << static_cast<int>(256 * Util::clamp(b, 0.0f, 0.999f)) << '\n';
}

SphereList g_world;

Vec3 RayColor(const Ray& r){
    HitData hitData = g_world.Hit(r, 0.0f, Util::infinity); 

    if(hitData.hit) {
        Vec3 normal = hitData.normal;
        Vec3 color = 0.5f * (normal + Vec3(1.0f,1.0f,1.0f));
        return color;
    }

    Vec3 unitDirection = UnitVector(r.GetDirection());
    float t = 0.5f * (unitDirection.y + 1.0f);
    return (1.0f - t) * Vec3(1.0f, 1.0f, 1.0f) + t * Vec3(0.5f, 0.7f, 1.0f);
}

int main() {
    srand(time(NULL));
    auto sphere = std::make_shared<Sphere>(0.5f,Vec3(0.0f,0.0f,-1.0f));
    auto sphere2 = std::make_shared<Sphere>(100.0f,Vec3(0.0f,-100.5f,-1.0f));

    g_world.Add(sphere2);
    g_world.Add(sphere);

    const float aspectRatio = 16.0f / 9.0f;

    const int image_width = 400; 
    const int image_height = static_cast<int>(image_width/ aspectRatio);


    Camera camera(Vec3(), aspectRatio, 2.0f);    

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n"; 

    const int samplesPerPixel = 100;
    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            Vec3 pixelColor(0.0f,0.0f,0.0f);
            for(int s = 0; s < samplesPerPixel; ++s)
            {
                float u = (i + Util::RandomFloat() )/ (image_width - 1);
                float v = (j + Util::RandomFloat() )/ (image_height - 1);

                Ray ray = camera.GetRay(u,v);
                pixelColor += RayColor(ray);
            }
            
            WriteColor(std::cout, pixelColor, samplesPerPixel);
        }
    }
    std::cerr << "\nDone\n";
    return 0;
}
