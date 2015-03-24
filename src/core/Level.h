#pragma once

#include "Entity.h"

class Level {
public:
  Level();

  virtual ~Level();

  void GenLevel(const Texture &texture, const ShaderProgram &program);

  void Draw(const Texture &texture, const glm::mat4 &Projection, const glm::mat4 &View);

  std::vector<Entity *> entities;
};
