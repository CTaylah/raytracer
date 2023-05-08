#pragma once

#include "Ray.h"

class Camera{

public:
    Camera(Vec3 cameraPosition, float aspectRatio, float viewportHeight);
    Ray GetRay(float u, float v) const;
private:
    float m_viewportHeight;
    float m_viewportWidth;
    float m_focalLength;

    Vec3 m_cameraPosition;
    Vec3 m_horizontalVector;
    Vec3 m_verticalVector;

    Vec3 m_lowerLeft;



};