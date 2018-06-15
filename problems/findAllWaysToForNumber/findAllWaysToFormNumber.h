#pragma once
#include <stdlib.h>     /* atoi */
#include <vector>
#include <string>

using namespace std;

// Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.
struct ResOption {
  int value;
  string str;
  ResOption(int v, string s): value(v), str(s) {}
};

class FindAdllWaysToFormNumber {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> output;
        if (num.empty())
            return output;
        
        auto res = eval(num);
        for(auto r: res) {
            if (r.value == target)
                output.push_back(r.str);
        }
        return output;
    }
    
private:
    vector<ResOption> eval(const string& num) {
        vector<ResOption> res;
        res.push_back(ResOption(atoi(num.c_str()), num));
        
        for(size_t i = 1; i < num.size(); i++) {
            auto leftRes = eval(num.substr(0, i));
            auto rightStr = num.substr(i);
            auto rightVal = atoi(rightStr.c_str());
            for(size_t j =0; j< leftRes.size(); j++) {
                res.push_back(ResOption(leftRes[j].value + rightVal, leftRes[j].str + "+" + rightStr ));
                res.push_back(ResOption(leftRes[j].value - rightVal, leftRes[j].str + "-" + rightStr ));
                res.push_back(ResOption(leftRes[j].value * rightVal, leftRes[j].str + "*" + rightStr ));
            }
        }
        
        return res;
    }
    
};