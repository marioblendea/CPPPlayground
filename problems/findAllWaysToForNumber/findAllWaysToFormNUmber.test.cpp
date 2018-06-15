#include "gtest/gtest.h"
#include "findAllWaysToFormNumber.h"

TEST(FindAdllWaysToFormNumber, test123) {
  FindAdllWaysToFormNumber s;
  auto res = s.addOperators("123", 6);
  EXPECT_EQ(res[0], "1+2+3");
  EXPECT_EQ(res[1], "1*2*3");
}


// TEST(FindAdllWaysToFormNumber, test232) {
//   FindAdllWaysToFormNumber s;
//   auto res = s.addOperators("232", 8);
//   EXPECT_EQ(res[0], "2*3+2");
//   EXPECT_EQ(res[1], "2+3*2");
// }
