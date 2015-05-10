#pragma once

#include "Animation.h"
#include "Platokdef.h"

#include <map>

enum EntityType {
  GROUND,
  PLAYER,
  ENEMY
};

enum AnimationType {
  IDLE,
  MOVE,
  JUMP
};

class Entity {
public:
  Entity();
  Entity(EntityType type);
  Entity(EntityType etype, AnimationType atype, float x, float y, float width, float height, const ShaderProgram& program, bool isFixed);
  virtual ~Entity();

  Animation *GetCurrentAnimation();

  AnimationType GetCurrentAnimationType();

  Animation *AddAnimation(AnimationType type, float x, float y, float width, float height, const ShaderProgram& program, bool isFixed);

  Animation *SetAnimation(AnimationType type);

  Animation *GetAnimation(AnimationType type);

  void SetEntityType(EntityType type);

  void Draw(const Texture &texture, const glm::mat4 &projection, const glm::mat4 &view);

  operator EntityType();

  EntityType GetEntityType();

protected:
  std::map<AnimationType, Animation *> animations;
  AnimationType currentAnimationType;
  Animation *currentAnimation;
  EntityType type;
};

