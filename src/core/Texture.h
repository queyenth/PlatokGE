#pragma once
#include <string>
#include <GL/glew.h>
#include <SOIL2/SOIL2.h>

class Texture {
public:
  Texture();
  Texture(std::string imagePath);

  ~Texture();
  
  bool LoadFromFile(std::string imagePath);
  void BindTexture() const;
  int GetWidth() const;
  int GetHeight() const;
  bool IsValid() const;

  inline operator GLuint() const {
    return image;
  }
private:
  GLuint image;
  int width;
  int height;
  bool isValid;
};
