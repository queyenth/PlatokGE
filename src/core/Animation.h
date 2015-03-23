#pragma once
#include <vector>

#include "Renderable.h"

class Animation : public Renderable {
public:
  Animation();
  Animation(float x, float y, float width, float height, const ShaderProgram& program, bool isFixed);
  
  virtual ~Animation();
  
  int GetCurrentFrame() const;
  void SetLoopMode(bool loop);
  void SetSpeed(double speed);
  void SetCurrentFrame(int currentFrame);
  void GenUVBuffers();
  void AddFrame(const Texture &texture);
  void AddFrame(const Texture &texture, Rect textureRect);

private:
  virtual void Render(const Texture &texture) override;
  virtual void RenderClean() override;

  std::vector<Rect> textureRects;
  std::vector<std::vector<GLfloat> > uv_buffers;
  std::vector<GLuint> uvbuffer;

  double speed;
  mutable double startAnimation;
  mutable int currentFrame;
  bool loop;
};
