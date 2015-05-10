#pragma once

#include <vector>

#include <GL/glew.h>
#include <glm.hpp>

#include "Texture.h"
#include "Renderable.h"

class Sprite : public Renderable {
public:
  Sprite();
  Sprite(float x, float y, float width, float height, const ShaderProgram& program, bool isFixed);
  
  virtual ~Sprite();
  
  void GenUVBuffers();
  virtual void GenAll() override;
  void SetTexture(const Texture &texture, Rect textureRect);
  void SetTexture(const Texture &texture);

private:
  virtual void Render(const Texture &texture) override;
  virtual void RenderClean() override;
  Rect textureRect;

  std::vector<glm::vec2> uv_buffer;
  GLuint uvbuffer;
};

/*class PhysicsSprite : public Renderable {
public:
  PhysicsSprite();
  PhysicsSprite(float x, float y, float width, float height, const ShaderProgram& program, bool isFixed);
  
  virtual ~PhysicsSprite();
  
  void GenUVBuffers();
  void SetTexture(const Texture &texture, Rect textureRect);
  void SetTexture(const Texture &texture);

private:
  virtual void Render(const Texture &texture) override;
  virtual void RenderClean() override;
  Rect textureRect;

  GLfloat uv_buffer[12];
  GLuint uvbuffer;
};*/