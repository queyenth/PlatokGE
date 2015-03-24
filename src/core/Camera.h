#pragma once

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

class Camera {
public:

  Camera();
  Camera(float x, float y);

  operator glm::mat4();
  glm::mat4 GetMatrix();
  void OffsetX(float x);
  void OffsetY(float y);

private:
  glm::mat4 view;
};
