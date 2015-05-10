#pragma once

#include "Entity.h"

#include "Level.h"

class Player : public Entity {
public:
  enum State {
    STADE,
    MOVE,
    JUMP,
    FALL,
    ALL
  };

  Player();
  Player(float x, float y, const Texture &texture, const ShaderProgram& program);
  virtual ~Player();

  bool CheckCollide(Level &level, EntityType type);

  void Update(Level &level);

  void Draw(const Texture &texture, const glm::mat4 &Projection, const glm::mat4 &View);

  void Jump();

  void SetState(State newState);

  State currentState;
  int currentJumpVel;
  
  static const int G = -2;
  static const int JUMPVEL = -30;
};
