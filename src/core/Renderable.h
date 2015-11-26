#pragma once

#include <vector>
#include <functional>

#include <GL/glew.h>
#include <glm/glm.hpp>

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
  void GenElementBuffers();
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
  void BeforeRender(std::function<void()>);
  void Move(float offsetX, float offsetY);
  void Rotate(float newAngle);
  void FlipX(bool isFlip);
  void FlipY(bool isFlip);
  bool IsFlippedX() const;
  bool IsFlippedY() const;

  virtual void GenAll();

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

  std::vector<glm::vec3> vertex_buffer;
  GLuint vertexbuffer;

  std::vector<glm::vec3> normal_buffer;
  GLuint normalbuffer;

  std::vector<unsigned short> element_buffer;
  GLuint elementbuffer;
  
  const ShaderProgram* program;
  std::function<void()> beforeRenderFunc;
  glm::mat4 matrix;
  bool positionChanged;
  bool isFixed;
  bool flipped;
};
