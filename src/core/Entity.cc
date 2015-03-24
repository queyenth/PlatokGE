#include "Entity.h"


Entity::Entity() {
  currentAnimation = nullptr;
}
Entity::Entity(EntityType type) {
  this->type = type;
  currentAnimation = nullptr;
}
Entity::Entity(EntityType etype, AnimationType atype, float x, float y, float width, float height, const ShaderProgram& program, bool isFixed) {
  animations.insert(std::pair<AnimationType, Animation *>(atype, new Animation(x, y, width, height, program, isFixed)));
  currentAnimation = animations[atype];
  currentAnimationType = atype;
  type = etype;
}
Entity::~Entity() {
  for (auto i : animations)
    delete i.second;
}

Animation *Entity::GetCurrentAnimation() {
  return currentAnimation;
}

AnimationType Entity::GetCurrentAnimationType() {
  return currentAnimationType;
}

Animation *Entity::AddAnimation(AnimationType type, float x, float y, float width, float height, const ShaderProgram& program, bool isFixed) {
  animations.insert(std::pair<AnimationType, Animation *>(type, new Animation(x, y, width, height, program, isFixed)));
  currentAnimation = animations[type];
  currentAnimationType = type;
  return currentAnimation;
}

Animation *Entity::SetAnimation(AnimationType type) {
  if (currentAnimation != nullptr)
    animations[type]->CopyLocation(currentAnimation);
  currentAnimation = animations[type];
  currentAnimationType = type;
  return currentAnimation;
  /*for (auto i : animations) {
    if (i.first == type) {
      if (currentAnimation != nullptr)
        i.second->CopyLocation(currentAnimation);
      currentAnimation = i.second;
      currentAnimationType = type;
      return currentAnimation;
    }
  }*/
}

Animation *Entity::GetAnimation(AnimationType type) {
  return animations[type];
  /*for (auto i : animations)
    if (i.first == type)
      return i.second;*/
}

void Entity::SetEntityType(EntityType type) {
  this->type = type;
}

void Entity::Draw(const Texture &texture, const glm::mat4 &projection, const glm::mat4 &view) {
  currentAnimation->Draw(texture, projection, view);
}

Entity::operator EntityType() {
  return type;
}

EntityType Entity::GetEntityType() {
  return type;
}
