#include "gtest/gtest.h"
#include "leastBricks.h"

TEST(LeastBricks, test123) {
  LeastBricks s;

  vector<vector<int>> v = {{1,2,2,1}, {3,1,2}, {1,3,2}, {2,4}, {3,1,2}, {1,3,1,1}};
  auto res = s.leastBricks(v);
  EXPECT_EQ(res, 2);


}
