#pragma once

class Texture;

class Rect {
public:
  
  Rect();
  
  Rect(float left, float top, float right, float bottom);

  Rect(const Texture &texture);

  float left;
  float top;
  float right;
  float bottom;
};
