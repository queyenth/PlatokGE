#include <stdio.h>
#include <gtest/gtest.h>

#include "../src/core/Screen.h"
#include "../src/core/Animation.h"
#include "../src/core/Sprite.h"
#include "../src/core/Entity.h"
#include "../src/core/Rect.h"

TEST(ScreenTest, ScreenResize) {
  Screen screen = Screen(640, 480, "test", false);
  screen.ResizeWindow(540, 640);
  EXPECT_EQ(screen.GetWidth(), 540);
  EXPECT_EQ(screen.GetHeight(), 640);
}

TEST(AnimationTest, AnimationDefaultConstructor) {
  Animation animation = Animation();
  EXPECT_EQ(animation.GetX(), 0);
  EXPECT_EQ(animation.GetY(), 0);
  EXPECT_EQ(animation.GetWidth(), 0);
  EXPECT_EQ(animation.GetHeight(), 0);
  EXPECT_EQ(animation.GetAngle(), 0);
  EXPECT_EQ(animation.GetCurrentFrame(), 0);
}

TEST(AnimationTest, AnimationConstructor) {
  Shader *vert = new Shader("VertexShader.vert", GL_VERTEX_SHADER);
  Shader *frag = new Shader("FragmentShader.frag", GL_FRAGMENT_SHADER);
  ShaderProgram program = ShaderProgram(*vert, *frag);
  delete vert;
  delete frag;
  Animation animation = Animation(50.0f, 50.0f, 50.0f, 50.0f, program, false);
  EXPECT_EQ(animation.GetX(), 50.0f);
  EXPECT_EQ(animation.GetY(), 50.0f);
  EXPECT_EQ(animation.GetWidth(), 50.0f);
  EXPECT_EQ(animation.GetHeight(), 50.0f);
  EXPECT_EQ(animation.GetAngle(), 0);
  EXPECT_EQ(animation.GetCurrentFrame(), 0);
}

TEST(AnimationTest, AnimationMove) {
  Shader *vert = new Shader("VertexShader.vert", GL_VERTEX_SHADER);
  Shader *frag = new Shader("FragmentShader.frag", GL_FRAGMENT_SHADER);
  ShaderProgram program = ShaderProgram(*vert, *frag);
  delete vert;
  delete frag;
  Animation animation = Animation(50.0f, 50.0f, 50.0f, 50.0f, program, false);
  animation.Move(10.0f, 10.0f);
  EXPECT_EQ(animation.GetX(), 60.0f);
  EXPECT_EQ(animation.GetY(), 60.0f);
  animation.Move(-100.0f, -10.0f);
  EXPECT_EQ(animation.GetX(), -40.0f);
  EXPECT_EQ(animation.GetY(), 50.0f);
}

TEST(RectTest, RectConstructor) {
  Rect rect(0.0f, 10.0f, 0.0f, 10.0f);
  EXPECT_EQ(rect.left, 0.0f);
  EXPECT_EQ(rect.top, 10.0f);
  EXPECT_EQ(rect.right, 0.0f);
  EXPECT_EQ(rect.bottom, 10.0f);
}

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from Main.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
