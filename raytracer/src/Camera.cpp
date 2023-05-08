#include "Camera.h"

Camera::Camera(Vec3 cameraPosition, float aspectRatio, float viewportHeight) 
    : m_cameraPosition(cameraPosition), m_viewportHeight(viewportHeight), m_focalLength(1.0f)
{
    m_viewportWidth = aspectRatio * m_viewportHeight;

    m_horizontalVector = Vec3(m_viewportWidth, 0.0f, 0.0f);
    m_verticalVector = Vec3(0.0f, m_viewportHeight, 0.0f);

    m_lowerLeft = m_cameraPosition - (m_horizontalVector/2.0f) - (m_verticalVector/2.0f) - Vec3(0,0,m_focalLength); 

}

Ray Camera::GetRay(float u, float v) const
{
    return Ray(m_cameraPosition, m_lowerLeft + u * m_horizontalVector + v * m_verticalVector - m_cameraPosition);
}