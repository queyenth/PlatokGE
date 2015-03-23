#pragma once

#include <vector>

#include <GL/glew.h>
#include <glm.hpp>

#include "Rect.h"
#include "Texture.h"
#include "Color.h"
#include "ShaderProgram.h"
#include "Shader.h"

class Renderable {
public:
  Renderable();
  Renderable(float x, float y, float width, float height, const ShaderProgram& program, bool isFixed);
  
  virtual ~Renderable();
  
  void Draw(const Texture &texture, const glm::mat4 &Projection, const glm::mat4 &View) ;

  void GenVertexBuffers();
  float GetX() const;
  float GetY() const;
  float GetWidth() const;
  float GetHeight() const;
  float GetAngle();
  glm::mat4 GetModelMatrix() const;
  ShaderProgram GetShaderProgram() const;
  Rect GetRect() const;
  void SetX(float x);
  void SetY(float y);
  void SetWidth(float width);
  void SetHeight(float height);
  void SetFixedMode(bool isFixed);
  void SetAngle(float angle);
  void SetShaderProgram(const ShaderProgram &program);
  void Move(float offsetX, float offsetY);
  void Rotate(float newAngle);
  void FlipX(bool isFlip);
  void FlipY(bool isFlip);
  bool IsFlippedX() const;
  bool IsFlippedY() const;

  void CopyLocation(Renderable *);

protected:
  virtual void Render(const Texture &texture) = 0;
  virtual void RenderClean() = 0;

  bool isFlippedX;
  bool isFlippedY;
  float x;
  float y;
  float width;
  float height;
  float angle;

  GLfloat vertex_buffer[18];
  GLuint vertexbuffer;

  GLfloat normal_buffer[18];
  GLuint normalbuffer;
  
  const ShaderProgram* program;
  glm::mat4 matrix;
  bool positionChanged;
  bool isFixed;
  bool flipped;
};
