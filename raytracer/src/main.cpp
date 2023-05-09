#include "Vec3.h"
#include "Sphere.h"
#include "Util.h"
#include "Camera.h"
#include <iostream>




Vec3 RandomInUnitSphere(){
    while(true){
        Vec3 p = Vec3::Random();;
        if(p.LengthSquared() >= 1.0f) 
            continue;

        return p;
    }
}

Vec3 RandomUnitVector(){
    return UnitVector(RandomInUnitSphere());
}

void WriteColor(std::ostream& out, Vec3 pixelColor, int samplesPerPixel){

    float scale = 1.0f / samplesPerPixel;

    Vec3 scaledColor = pixelColor * scale;
    out << static_cast<int>(256 * Util::clamp(std::sqrt(scaledColor.x), 0.0, 0.999)) << ' '
        << static_cast<int>(256 * Util::clamp(std::sqrt(scaledColor.y), 0.0, 0.999)) << ' '
        << static_cast<int>(256 * Util::clamp(std::sqrt(scaledColor.z), 0.0, 0.999)) << '\n';
}

SphereList g_world;

Vec3 RayColor(const Ray& r, int depth){
    HitData hitData = g_world.Hit(r, 0.0001, Util::infinity); 

    if(depth <= 0)
        return Vec3(0.0f, 0.0f, 0.0f);

    if(hitData.hit) {
        Vec3 normal = hitData.normal;

        Vec3 randomPoint = hitData.point + normal + RandomUnitVector();
        Ray ray2(hitData.point, randomPoint - hitData.point);
        return 0.5 * RayColor(ray2, depth - 1);
    }

    Vec3 unitDirection = UnitVector(r.GetDirection());
    float t = 0.5f * (unitDirection.y + 1.0f);
    return (1.0f - t) * Vec3(1.0f, 1.0f, 1.0f) + t * Vec3(0.5f, 0.7f, 1.0f);
}

int main() {
    auto sphere = std::make_shared<Sphere>(0.5f,Vec3(0.0f,0.0f,-1.0f), Material(Vec3(0.4f,0.6f,0.3f)));
    auto sphere2 = std::make_shared<Sphere>(100.0f,Vec3(0.0f,-100.5f,-1.0f), Material(Vec3(0.8f,0.3f,0.0f)));

    g_world.Add(sphere);
    g_world.Add(sphere2);

    const float aspectRatio = 16.0f / 9.0f;

    const int image_width = 720; 
    const int image_height = static_cast<int>(image_width/ aspectRatio);

    Camera camera(Vec3(0.0f, 0.0f, 0.0f), aspectRatio, 2.0f);

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n"; 

    const int samplesPerPixel = 100;
    const int maxDepth = 50;
    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            Vec3 pixelColor(0.0f,0.0f,0.0f);
            for(int s = 0; s < samplesPerPixel; ++s)
            {
                float u = (i + Util::RandomFloat() )/ (image_width - 1);
                float v = (j + Util::RandomFloat() )/ (image_height - 1);

                Ray ray = camera.GetRay(u,v);
                pixelColor += RayColor(ray, maxDepth);
            }
            
            WriteColor(std::cout, pixelColor, samplesPerPixel);
        }
    }
    std::cerr << "\nDone\n";
    return 0;
}
