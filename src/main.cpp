#include "Vec3.h"
#include "Ray.h"

#include <iostream>


struct HitData
{
    HitData(bool hit, const Vec3& point) : hit(hit), point(point) {}
    bool hit;
    Vec3 point;
    //Vec3 color;
};



HitData hitSphere(const Vec3& center, float radius, const Ray& ray)
{
    Vec3 direction = ray.GetDirection();
    Vec3 origin = ray.GetOrigin();

    float a = Dot(direction, direction);
    float b = 2 * Dot(direction, origin - center);
    float c = Dot(origin - center, origin - center) - radius * radius;
    
    float discriminant= b * b - 4 * a * c;

    if(discriminant < 0) 
        return HitData(false, Vec3(0.0f,0.0f,0.0f));

    float t = ((-b - std::sqrt(discriminant)) / (2.0f * a));

    if(t < 0.0f) 
        return HitData(false, Vec3(0.0f,0.0f,0.0f));

    return HitData(true, ray.At(t));
}


Vec3 RayColor(const Ray& r){
    Vec3 unitDirection = UnitVector(r.GetDirection());
    float t = 0.5f * (unitDirection.y + 1.0f);

    HitData hitData = hitSphere(Vec3(0.0f, 0.0f, -1.0f), 0.5f, r);

    if(hitData.hit) {
        Vec3 normal = UnitVector(hitData.point - Vec3(0.0f, 0.0f, -1.0f));
        Vec3 color = 0.5f * Vec3(normal.x + 1, normal.y + 1, normal.z + 1);
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
