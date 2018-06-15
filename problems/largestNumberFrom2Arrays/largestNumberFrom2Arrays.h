#pragma once
#include <vector>

using namespace std;

struct Pos {
  unsigned int array;
  unsigned int idxInArray;
  Pos(unsigned int a, unsigned int iInA) : array(a), idxInArray(iInA) {}
};

class LargestNumberFrom2Arrays {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> output;
        vector<std::vector<Pos>> helper(10);
        for(size_t i = 0; i < nums1.size(); i++) {
          helper[nums1[i]].push_back(Pos(0, i));
        }
        for(size_t i = 0; i < nums2.size(); i++) {
          helper[nums2[i]].push_back(Pos(1, i));
        }

        size_t r1 = nums1.size();
        size_t r2 = nums2.size();
        for(int i = 0; i < k; i++) {
          for (int j = 9; j >= 0; j--) {
            if (!helper[j].empty()) {
              auto p = helper[j][0];

              // can I use it
              if (p.array == 0) {
                if (p.idxInArray < nums1.size() - r1)
                  continue;
                if ((unsigned int)(k - i - 1) > r2 + nums1.size() - p.idxInArray - 1)
                  continue;
                else
                  r1 = nums1.size() - p.idxInArray - 1;
              }
              else {
                if (p.idxInArray < nums2.size() - r2)
                  continue;

                if ((unsigned int)(k - i - 1) > r1 + nums2.size() - p.idxInArray - 1)
                  continue;
                else
                  r2 = nums2.size() - p.idxInArray - 1;
              }

              // use it
              output.push_back(j);
              
              // remove it
              auto sz = helper[j].size();
              if (sz > 1) {
                helper[j][0] = helper[j][sz - 1];
              }
              helper[j].pop_back();
              break;
            }
          }
        }
        return output;
    }
};