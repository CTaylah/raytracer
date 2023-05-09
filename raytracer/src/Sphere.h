#pragma once

#include "Ray.h"
#include "HitData.h"

#include <vector>
#include <memory>

class Sphere
{
public:
    Sphere(float radius, Vec3 center) : m_radius(radius), m_center(center) {}
    Sphere(float radius, Vec3 center, Material mat) : m_radius(radius), m_center(center), m_material(mat) {}
    float GetRadius() const { return m_radius; };
    Vec3 GetCenter() const { return m_center; };

    HitData Hit(const Ray& ray, float tMin, float tMax);
     
private:
    float m_radius;
    Vec3 m_center;
    Vec3 m_color;
    Material m_material;

};

class SphereList
{
public:
    void Add(std::shared_ptr<Sphere> sphere) { m_sphereList.push_back(sphere); }
    void Clear(){ m_sphereList.clear(); }
    std::shared_ptr<Sphere> Get(int index){ return m_sphereList[index];}

    //Returns true if anything was hit
    HitData Hit(const Ray& ray, float tMin, float tMax) const;

private:
    std::vector<std::shared_ptr<Sphere>> m_sphereList;

};