// 31. Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
// The replacement must be in-place and use only constant extra memory.
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
#pragma once
#include <vector>

class Permutation {
  public:
    Permutation() {

    }

    void nextPermutation(std::vector<int>& nums);

  private:
    int findPosToGoUpNext(std::vector<int>& nums);
    int findPosWhereNextValueIs(int idxStart, std::vector<int>& nums);
    void swapAt(int idx1, int idx2, std::vector<int>& nums);
    void sortPost(int idxStart, std::vector<int>& nums);
};
