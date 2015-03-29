#include "Renderable.h"

#include <gtc/matrix_transform.hpp>

Renderable::Renderable() : x(0), y(0), width(0), height(0), angle(0), positionChanged(true),
isFlippedX(false), isFlippedY(false), isFixed(false) {
}


Renderable::Renderable(float x, float y, float width, float height, const ShaderProgram& program,
  bool isFixed) : x(x), y(y), width(width), height(height), angle(0), positionChanged(true),
  isFlippedX(false), isFlippedY(false), isFixed(isFixed), program(&program) {
}

Renderable::~Renderable() {
  if (glIsBuffer(vertexbuffer))
    glDeleteBuffers(1, &vertexbuffer);
  if (glIsBuffer(normalbuffer))
    glDeleteBuffers(1, &normalbuffer);
}

void Renderable::Draw(const Texture &texture, const glm::mat4 &Projection, const glm::mat4 &View) {
  if (!width || !height || !texture.IsValid() || !glIsBuffer(vertexbuffer) || !glIsBuffer(normalbuffer)) return;

  glm::mat4 T;
  if (isFixed)
    T = glm::translate(glm::mat4(1.0f), glm::vec3(x + width / 2 - View[3][0], y + height / 2 - View[3][1], 0.0f));
  else
    T = glm::translate(glm::mat4(1.0f), glm::vec3(x + width / 2, y + height / 2, 0.0f));
  matrix = glm::rotate(T, (float)angle, glm::vec3(0.0f, 0.0f, 1.0f));

  GLuint MatrixID = glGetUniformLocation(*program, "MVP");

  glm::mat4 MVP = Projection * View * matrix;

  glUseProgram(*program);

  glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  glVertexAttribPointer(
    0,
    3,
    GL_FLOAT,
    GL_FALSE,
    0,
    (void *)0
  );

  glEnableVertexAttribArray(2);
  glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
  glVertexAttribPointer(
    2,
    3,
    GL_FLOAT,
    GL_FALSE,
    0,
    (void *)0
  );

  Render(texture);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);

  glDrawElements(
    GL_TRIANGLES,
    element_buffer.size(),
    GL_UNSIGNED_SHORT,
    (void*)0
  );

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(2);
  RenderClean();
}

float Renderable::GetX() const {
  return x;
}

float Renderable::GetY() const {
  return y;
}

float Renderable::GetWidth() const {
  return width;
}

float Renderable::GetHeight() const {
  return height;
}

float Renderable::GetAngle() {
  return angle;
}

glm::mat4 Renderable::GetModelMatrix() const {
  return matrix;
}

ShaderProgram Renderable::GetShaderProgram() const {
  return *program;
}

Rect Renderable::GetRect() const {
  return Rect(x, y, x + width, y + height);
}

void Renderable::SetX(float x) {
  this->x = x;
  positionChanged = true;
}

void Renderable::SetY(float y) {
  this->y = y;
  positionChanged = true;
}

void Renderable::SetWidth(float width) {
  this->width = width;
}

void Renderable::SetHeight(float height) {
  this->height = height;
}

void Renderable::GenVertexBuffers() {
  glm::vec3 v[4];
  v[0] = glm::vec3(-(width / 2), -(height / 2), 0.0f);
  v[1] = glm::vec3(width / 2, -(height / 2), 0.0f);
  v[2] = glm::vec3(-(width / 2), height / 2, 0.0f);
  v[3] = glm::vec3(width / 2, height / 2, 0.0f);

  for (auto i = 0; i < 4; i++)
    vertex_buffer.push_back(v[i]);

  glm::vec3 v1normal = glm::normalize(glm::cross(v[1]-v[0], v[2]-v[0]));
  for (auto i = 0; i < 4; i++)
    normal_buffer.push_back(v1normal);

  if (glIsBuffer(normalbuffer))
    glDeleteBuffers(1, &normalbuffer);
  glGenBuffers(1, &normalbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
  glBufferData(GL_ARRAY_BUFFER, normal_buffer.size()*sizeof(glm::vec3), &normal_buffer[0], GL_STATIC_DRAW);

  if (glIsBuffer(vertexbuffer))
    glDeleteBuffers(1, &vertexbuffer);
  glGenBuffers(1, &vertexbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  glBufferData(GL_ARRAY_BUFFER, vertex_buffer.size()*sizeof(glm::vec3), &vertex_buffer[0], GL_STATIC_DRAW);
}

void Renderable::GenElementBuffers() {
  element_buffer.push_back(0);
  element_buffer.push_back(1);
  element_buffer.push_back(2);
  element_buffer.push_back(2);
  element_buffer.push_back(3);
  element_buffer.push_back(1);
  if (glIsBuffer(elementbuffer))
    glDeleteBuffers(1, &elementbuffer);
  glGenBuffers(1, &elementbuffer);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, element_buffer.size() * sizeof(unsigned short), &element_buffer[0], GL_STATIC_DRAW);
}



void Renderable::SetFixedMode(bool isFixed) {
  this->isFixed = isFixed;
}

void Renderable::SetAngle(float angle) {
  this->angle = angle;
  positionChanged = true;
}

void Renderable::SetShaderProgram(const ShaderProgram &program) {
  this->program = &program;
}

void Renderable::Move(float offsetX, float offsetY) {
  SetX(x + offsetX);
  SetY(y + offsetY);
}

void Renderable::Rotate(float newAngle) {
  angle += newAngle;
  positionChanged = true;
}

void Renderable::FlipX(bool isFlip) {
  isFlippedX = isFlip;
  flipped = true;
}

void Renderable::FlipY(bool isFlip) {
  isFlippedY = isFlip;
  flipped = true;
}

bool Renderable::IsFlippedX() const {
  return isFlippedX;
}

bool Renderable::IsFlippedY() const {
  return isFlippedY;
}

void Renderable::CopyLocation(Renderable *other) {
  this->x = other->x;
  this->y = other->y;
  positionChanged = true;
}

void Renderable::GenAll() {
  GenVertexBuffers();
  GenElementBuffers();
}