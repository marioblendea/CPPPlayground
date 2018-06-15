#include "gtest/gtest.h"
#include "largestNumberFrom2Arrays.h"

TEST(LargestNumberFrom2Arrays, test123) {
  LargestNumberFrom2Arrays s;
  std::vector<int> v1 = {3, 4, 6, 5};
  std::vector<int> v2 = {9, 1, 2, 5, 8, 3};

  auto res = s.maxNumber(v1, v2, 3);
  EXPECT_EQ(res[0], 9);
  EXPECT_EQ(res[1], 8);
  EXPECT_EQ(res[2], 6);
  // EXPECT_EQ(res[3], 5);
  // EXPECT_EQ(res[4], 3);
}
