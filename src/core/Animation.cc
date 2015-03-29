#include "Animation.h"

#include <GLFW/glfw3.h>
#include <gtc/matrix_transform.hpp>

Animation::Animation() : Renderable(), currentFrame(0), speed(0.1), startAnimation(0) {
}


Animation::Animation(float x, float y, float width, float height, const ShaderProgram& program, bool isFixed) :
  Renderable(x, y, width, height, program, isFixed), currentFrame(0), speed(0.1), startAnimation(0) {
}

Animation::~Animation() {
  for (auto i : uvbuffer)
    if (glIsBuffer(i))
      glDeleteBuffers(1, &i);
}
  
void Animation::Render(const Texture &texture) {
  GLuint TextureID = glGetUniformLocation(*program, "myTextureSampler");

  glActiveTexture(GL_TEXTURE0);
  texture.BindTexture();
  glUniform1i(TextureID, 0);

  if (flipped) {
    if (isFlippedY)
      for (auto i : textureRects)
        std::swap(i.bottom, i.top);
    if (isFlippedX)
      for (auto i : textureRects)
        std::swap(i.left, i.right);
    GenUVBuffers();
    flipped = false;
  }

  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, uvbuffer[currentFrame]);
  glVertexAttribPointer(
    1,
    2,
    GL_FLOAT,
    GL_FALSE,
    0,
    (void *)0
  );

  if (currentFrame+1 < textureRects.size()) {
    if (glfwGetTime() - startAnimation >= speed) {
      currentFrame++;
      startAnimation = glfwGetTime();
    }
  }
  else if (loop && glfwGetTime() - startAnimation >= speed) {
    currentFrame = 0;
    startAnimation = glfwGetTime();
  }
}

void Animation::RenderClean() {
  glDisableVertexAttribArray(1);
  glDisableVertexAttribArray(2);
}

int Animation::GetCurrentFrame() const {
  return currentFrame;
}

void Animation::SetLoopMode(bool loop) {
  this->loop = loop;
}

void Animation::SetCurrentFrame(int currentFrame) {
  this->currentFrame = currentFrame;
}

void Animation::SetSpeed(double speed) {
  this->speed = speed;
}

void Animation::AddFrame(const Texture &texture, Rect textureRect) {
  textureRects.push_back(Rect(textureRect.left/texture.GetWidth(), textureRect.top/texture.GetHeight(), textureRect.right/texture.GetWidth(), textureRect.bottom/texture.GetHeight()));
}

void Animation::GenUVBuffers() {
  for (int i = 0; i < uv_buffers.size(); i++) {
    uv_buffers[i].clear();
  }
  uv_buffers.clear();
  for (int i = 0; i < uvbuffer.size(); i++) {
    if (glIsBuffer(uvbuffer[i])) {
      glDeleteBuffers(1, &uvbuffer[i]);
    }
  }
  uvbuffer.clear();
  for (int i = 0; i < textureRects.size(); i++) {
    std::vector<glm::vec2> uv_buffer(4);
    uv_buffer[0] = glm::vec2(textureRects[i].left, textureRects[i].top);
    uv_buffer[1] = glm::vec2(textureRects[i].right, textureRects[i].top);
    uv_buffer[2] = glm::vec2(textureRects[i].left, textureRects[i].bottom);
    uv_buffer[3] = glm::vec2(textureRects[i].right, textureRects[i].bottom);
    uv_buffers.push_back(uv_buffer);

    uvbuffer.push_back(0);
    if (glIsBuffer(uvbuffer[i]))
      glDeleteBuffers(1, &uvbuffer[i]);
    glGenBuffers(1, &uvbuffer[i]);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer[i]);
    glBufferData(GL_ARRAY_BUFFER, uv_buffer.size() * sizeof(glm::vec2), &uv_buffer[0], GL_STATIC_DRAW);
  }

}
void Animation::AddFrame(const Texture &texture) {
  Rect textureRect = Rect(texture);
  textureRects.push_back(Rect(textureRect.left/texture.GetWidth(), textureRect.top/texture.GetHeight(), textureRect.right/texture.GetWidth(), textureRect.bottom/texture.GetHeight()));
}

void Animation::GenAll() {
  GenUVBuffers();
  Renderable::GenAll();
}