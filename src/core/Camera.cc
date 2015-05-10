#include "Camera.h"

Camera::Camera() {
  view = glm::lookAt(
    glm::vec3(0, 0, 2),
    glm::vec3(0, 0, 0),
    glm::vec3(0, 1, 0)
  );
}

Camera::Camera(float x, float y) {
  view = glm::lookAt(
    glm::vec3(0, 0, 2),
    glm::vec3(0, 0, 0),
    glm::vec3(0, 1, 0)
  );
  OffsetX(x);
  OffsetY(y);
}

Camera::operator glm::mat4() {
  return view;
}

glm::mat4 Camera::GetMatrix() {
  return view;
}

void Camera::OffsetX(float x) {
  view = glm::translate(view, glm::vec3(x, 0, 0));
}

void Camera::OffsetY(float y) {
  view = glm::translate(view, glm::vec3(0, y, 0));
}
