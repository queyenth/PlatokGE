#include <stdio.h>
#include <gtest/gtest.h>

TEST(CheckTest, JustChecking) {
  EXPECT_EQ(1, 1);
  EXPECT_GT(5, 0);
}

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from Main.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}