#pragma once
#include <vector>
using namespace std;

class IsToeplitzMatrix {
public:
  static bool isToeplitzMatrix(const vector<vector<int>>& matrix) {
    auto n = matrix.size();
    if (n == 0) return false;
    auto m = matrix[0].size();
    if (m == 0) return false;
    // there are m + n - 1 diagonals (-1 because of the one starting at 0,0)
    for(unsigned int k = 0; k <  m + n - 1; k++) {
      int idx = k - n;
      unsigned int i = 0;
      unsigned int j = idx;
      if (idx < 0) {
        j = 0;
        i = -idx - 1;
      }
      auto val = matrix[i][j];
      while(i < n  && j < m ) {
        if (matrix[i][j] != val) {
          return false;
        }
        i++;
        j++;
      }
    }
    return true;
  }
};