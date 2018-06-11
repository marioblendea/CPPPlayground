#include "gtest/gtest.h"
#include "findSubsequences.h"

TEST(FindSubsequencesTest, ShouldFindJustOneChar) {
  auto res = FindSubsequences::Find("abcxdfefa", {"bcff", "bd", "bb", "ff" });
  EXPECT_EQ(true, res[0]);
  EXPECT_EQ(true, res[1]);
  EXPECT_EQ(false, res[2]);
  EXPECT_EQ(true, res[3]);
}
