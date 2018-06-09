#include <iostream>

#include "problems/parantheses/parans.h"
#include "problems/printCombinationsOfWordsFromDigitsOnPhone/combinations.h"
#include "problems/LRU/LRU.h"
#include "problems/nextPermutation/nextPermutation.h"
#include "gtest/gtest.h"

using namespace std;

int main(int argc, char **argv){
    cout << "Print Combinations for string 23\r\n";
    Combinations c;
    c.printWords(L"23");

    cout << "\r\n\r\nPrint all valid paranthesis combinations for 3 sets\r\n";
    Parans p(3);
    auto res = p.PrintAll();
    for(auto r: res) {
        std::cout << r << "\r\n";
    }

    // LRU
    cout << "\r\nLRU cache test\r\n";
    LRUCache cache(2);
    cache.Put(1, 1);
    cache.Put(2, 2);
    std::cout << cache.Get(1);    // returns 1
    cache.Put(3, 3); // evicts key 2
    std::cout << cache.Get(2);    // returns -1 (not found)
    cache.Put(4, 4); // evicts key 1
    std::cout << cache.Get(1);    // returns -1 (not found)
    std::cout << cache.Get(3);    // returns 3
    std::cout << cache.Get(4);    // returns 4

    // next Permutation
    cout << "\r\n\r\nPrint next combination from 1,2,4,3,5\r\n";
    Permutation perm;
    vector<int> v = {1,2,4,3,5};
    perm.nextPermutation(v);
    for (int i = 0; i <  v.size(); i++)
        std::cout << v[i];
 
     ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}