#include "Sprite.h"

#include <gtc/matrix_transform.hpp>
#include <map>

Sprite::Sprite() : Renderable() {
}

Sprite::Sprite(float x, float y, float width, float height, const ShaderProgram& program,
  bool isFixed) : Renderable(x, y, width, height, program, isFixed) {
}

Sprite::~Sprite() {
  if (glIsBuffer(uvbuffer))
    glDeleteBuffers(1, &uvbuffer);
}

void Sprite::Render(const Texture &texture) {
  GLuint TextureID = glGetUniformLocation(*program, "myTextureSampler");

  if (flipped) {
    if (isFlippedY)
      std::swap(textureRect.bottom, textureRect.top);
    if (isFlippedX)
      std::swap(textureRect.left, textureRect.right);
    GenUVBuffers();
    flipped = false;
  }

  glActiveTexture(GL_TEXTURE0);
  texture.BindTexture();
  glUniform1i(TextureID, 0);

  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
  glVertexAttribPointer(
    1,
    2,
    GL_FLOAT,
    GL_FALSE,
    0,
    (void *)0
  );

}

void Sprite::RenderClean() {
  glDisableVertexAttribArray(1);
  glDisableVertexAttribArray(2);
}

void Sprite::GenUVBuffers() {
  glm::vec2 v[4];
  v[0] = glm::vec2(this->textureRect.left, this->textureRect.top);
  v[1] = glm::vec2(this->textureRect.right, this->textureRect.top);
  v[2] = glm::vec2(this->textureRect.left, this->textureRect.bottom);
  v[3] = glm::vec2(this->textureRect.right, this->textureRect.bottom);

  for (auto i = 0; i < 4; i++)
    uv_buffer.push_back(v[i]);

  if (glIsBuffer(uvbuffer))
    glDeleteBuffers(1, &uvbuffer);
  glGenBuffers(1, &uvbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
  glBufferData(GL_ARRAY_BUFFER, uv_buffer.size()*sizeof(glm::vec2), &uv_buffer[0], GL_STATIC_DRAW);
}

void Sprite::SetTexture(const Texture &texture, Rect textureRect) {
  this->textureRect = Rect(textureRect.left/texture.GetWidth(), textureRect.top/texture.GetHeight(), textureRect.right/texture.GetWidth(), textureRect.bottom/texture.GetHeight());
}

void Sprite::SetTexture(const Texture &texture) {
  textureRect = Rect(texture);
  this->textureRect = Rect(textureRect.left/texture.GetWidth(), textureRect.top/texture.GetHeight(), textureRect.right/texture.GetWidth(), textureRect.bottom/texture.GetHeight());
}

void Sprite::GenAll() {
  GenUVBuffers();
  Renderable::GenAll();
}
