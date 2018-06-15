#pragma once
#include <vector>
#include <unordered_map>

using namespace std;

class LeastBricks {
public:
  int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> map;
    int max = 0;
    for(unsigned int i = 0; i < wall.size(); i++) {
      auto line = wall[i];
      auto pos = 0;
      for(unsigned int j=0; j < line.size() - 1; j++) {
        pos += line[j];
        if (map.find(pos) == map.end()) {
          map[pos] = 0;
        }
        map[pos]++;
        if (map[pos] > max)
          max = map[pos];
      }
    }
    return wall.size() - max;
  }
};