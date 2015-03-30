#include <stdio.h>
#include <gtest/gtest.h>

#include "../src/core/Screen.h"

TEST(CheckTest, JustChecking) {
  EXPECT_EQ(1, 1);
  EXPECT_GT(5, 0);
}

TEST(ScreenTest, ScreenResize) {
  Screen screen = Screen(640, 480, "test", false);
  screen.ResizeWindow(540, 640);
  EXPECT_EQ(screen.GetWidth(), 540);
  EXPECT_EQ(screen.GetHeight(), 640);
}

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from Main.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
