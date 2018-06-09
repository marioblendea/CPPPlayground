#include "gtest/gtest.h"

TEST(myFirstTest, simpleCheck) {
  EXPECT_EQ(1, 1);
}

TEST(MySecondTest, shouldfail) {
  EXPECT_FALSE(false);
}