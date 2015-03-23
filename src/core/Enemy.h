#pragma once

#include "Entity.h"

#include "Physics.h"

#include "Level.h"

class Enemy : public Entity {
public:
  enum State {
    STADE,
    MOVE,
    JUMP,
    FALL,
    ALL
  };

  Enemy() {}

  Enemy(float x, float y, float width, float height, const Texture &texture, const ShaderProgram &program) {
    animations.insert(std::pair<AnimationType, Animation*>(AnimationType::IDLE, new Animation(x, y, 32, 64, program, false)));
    Animation *animation = GetAnimation(AnimationType::IDLE);
    animation->AddFrame(texture, Rect(0, 133, 32, 197));
    animation->SetLoopMode(true);
    animation->GenVertexBuffers();
    animation->GenUVBuffers();
    animations.insert(std::pair<AnimationType, Animation*>(AnimationType::MOVE, new Animation(x, y, 32, 64, program, false)));
    animation = GetAnimation(AnimationType::MOVE);
    animation->AddFrame(texture, Rect(66, 133, 97, 197));
    animation->AddFrame(texture, Rect(99, 133, 130, 197));
    animation->AddFrame(texture, Rect(132, 133, 163, 197));
    animation->SetLoopMode(true);
    animation->GenVertexBuffers();
    animation->GenUVBuffers();
    animations.insert(std::pair<AnimationType, Animation*>(AnimationType::JUMP, new Animation(x, y, 32, 64, program, false)));
    animation = GetAnimation(AnimationType::JUMP);
    animation->AddFrame(texture, Rect(33, 133, 64, 197));
    animation->SetLoopMode(true);
    animation->GenVertexBuffers();
    animation->GenUVBuffers();
    SetAnimation(AnimationType::IDLE);
    currentJumpVel = 0;
    currentState = STADE;
  }

  virtual ~Enemy() {

  }

  bool CheckCollide(Level &level, EntityType type) {
    bool isCollide = false;
    Animation *animation = GetCurrentAnimation();
    Rect playerRect = animation->GetRect();
    for (auto i : level.entities) {
      if (*i == type) {
        Rect blockRect = i->GetCurrentAnimation()->GetRect();
        isCollide = Physics::CheckCollide(playerRect, blockRect);
      }
      if (isCollide)
        return true;
    }
    return false;
  }

  void Update(Level &level) {

  }

  void Draw(const Texture &texture, const glm::mat4 &Projection, const glm::mat4 &View) {
    Entity::Draw(texture, Projection, View);
  }

  int currentJumpVel;
  State currentState;

  static const int G = -2;
  static const int JUMPVEL = -30;
};