#pragma once

#include <string>
#include <vector>
#include <unordered_map>

struct Sequence {
  int seqIdx; // index for sequence in the "sequences" input vector
  int charIdx; // index for the character in the current sequence (inner index)
  Sequence(int ci, int si): charIdx(ci), seqIdx(si) {

  }
};

class FindSubsequences
{
  public:
    static std::vector<bool> Find(const std::string& input, const std::vector<std::string>& sequences)
    {
      if (input.empty() || sequences.empty())
        throw "invalid input";

      // result; true on position i, means sequence with index i in "sequences" is found in input; false otherwise
      std::vector<bool> res; 

      // by default assume no sequences are found in "input"
      for(unsigned int i = 0; i < sequences.size(); i++)
        res.push_back(false);

      // map between the current character in "input" and a vector of sequences need that character next
      std::unordered_map<char, std::vector<Sequence>> map; 
      
      // intiatialize map with the first letter of each sequence
      for(auto i = 0; i < sequences.size(); i++) {
        if (sequences[i].empty())
          throw "invalid input";

        map[sequences[i][0]].push_back(Sequence(0, i));
      }

      // for each character in input, use "map" to find all sequenced that need it and move the inner index in those sequences forward
      for (auto ch: input) {
        auto sequencesThatNeedThisCharNextIt = map.find(ch);
        if (sequencesThatNeedThisCharNextIt == map.end())
          continue; // there are no sequences that need this character next

        auto& sequencesThatNeedThisCharNext = sequencesThatNeedThisCharNextIt->second;
        size_t j = 0;
        while (j < sequencesThatNeedThisCharNext.size()) {
          auto& seq = sequencesThatNeedThisCharNext[j];

          seq.charIdx++; // found the needed character; move idx of needed character forward
          if (seq.charIdx == sequences[seq.seqIdx].size())
            res[seq.seqIdx] = true; // found the sequence at position seqIdx

          auto newCh = sequences[seq.seqIdx][seq.charIdx];
          if (newCh == ch) {
            // same character; just move to the next sequence
            j++;
          }
          else {
            // insert this sequence in the array of sequences for the new character
            map[newCh].push_back(Sequence(seq));
            // remove sequence from current array of sequence (by moving the last element in the array over current one and popping from the end)
            seq.charIdx = sequencesThatNeedThisCharNext[sequencesThatNeedThisCharNext.size() - 1].charIdx;
            seq.seqIdx = sequencesThatNeedThisCharNext[sequencesThatNeedThisCharNext.size() - 1].seqIdx;
            sequencesThatNeedThisCharNext.pop_back();
          }
        }
      }

      return res;
    }
};