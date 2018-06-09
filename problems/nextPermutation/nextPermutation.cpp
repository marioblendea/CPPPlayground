#include "nextPermutation.h"

using namespace std;

void Permutation::nextPermutation(vector<int>& nums) {
  int idxToGoUp = findPosToGoUpNext(nums);
  if (idxToGoUp != -1) {
    int idxNextValue = findPosWhereNextValueIs(idxToGoUp, nums);
    swapAt(idxToGoUp, idxNextValue, nums);
  }
  sortPost(idxToGoUp, nums);
}

int Permutation::findPosToGoUpNext(std::vector<int>& nums) {
  for(auto i = nums.size() - 1; i > 0; i--) {
    if (nums[i] > nums[i-1])
      return (int)i-1;
  }
  return -1;
}

int Permutation::findPosWhereNextValueIs(int idxStart, std::vector<int>& nums){
  int min = nums[idxStart + 1];
  int posMin = idxStart + 1;
  for(int i = idxStart + 2; i < nums.size(); i++) {
    if (nums[i] < min) {
      min = nums[i];
      posMin = i;
    }
  }
  return posMin;
}

void Permutation::swapAt(int idx1, int idx2, std::vector<int>& nums){
  auto temp = nums[idx1];
  nums[idx1] = nums[idx2];
  nums[idx2] = temp;
}

void Permutation::sortPost(int idxStart, std::vector<int>& nums){
  for (int i = 0; i < (nums.size() - idxStart - 1) / 2 ; i++) {
    swapAt(idxStart + 1 + i, (int)nums.size() - i - 1, nums);
  }
}