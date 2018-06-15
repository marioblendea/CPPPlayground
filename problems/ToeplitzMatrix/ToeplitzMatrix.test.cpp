#include "gtest/gtest.h"
#include "ToeplitzMatrix.h"

TEST(ToeplitzMatrix, test123) {
  IsToeplitzMatrix s;
  vector<vector<int>> v = {{1,2,3,4}, {5,1,2,3}, {9,5,1,2}};
  auto res = s.isToeplitzMatrix(v);
  EXPECT_EQ(res, true);

  vector<vector<int>> v2 = {{1,2}, {2,2}};
  res = s.isToeplitzMatrix(v2);
  EXPECT_EQ(res, false);

}
