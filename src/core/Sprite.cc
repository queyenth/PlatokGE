#include "Sprite.h"

#include <gtc/matrix_transform.hpp>

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
  uv_buffer[0] = uv_buffer[8] = uv_buffer[10] = this->textureRect.left;
  uv_buffer[1] = uv_buffer[3] = uv_buffer[11] = this->textureRect.top;
  uv_buffer[2] = uv_buffer[4] = uv_buffer[6] = this->textureRect.right;
  uv_buffer[5] = uv_buffer[7] = uv_buffer[9] = this->textureRect.bottom;

  if (glIsBuffer(uvbuffer))
    glDeleteBuffers(1, &uvbuffer);
  glGenBuffers(1, &uvbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(uv_buffer), uv_buffer, GL_STATIC_DRAW);
}


void Sprite::SetTexture(const Texture &texture, Rect textureRect) {
  this->textureRect = Rect(textureRect.left/texture.GetWidth(), textureRect.top/texture.GetHeight(), textureRect.right/texture.GetWidth(), textureRect.bottom/texture.GetHeight());
}

void Sprite::SetTexture(const Texture &texture) {
  textureRect = Rect(texture);
  this->textureRect = Rect(textureRect.left/texture.GetWidth(), textureRect.top/texture.GetHeight(), textureRect.right/texture.GetWidth(), textureRect.bottom/texture.GetHeight());
}