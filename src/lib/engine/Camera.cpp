#include "Camera.h"

Camera::Camera() :
    transform(Transform())
{}

Camera::Camera(Vec3 position) :
    transform(Transform(position))
{}

Camera::Camera(Transform transform) :
    transform(transform)
{}
