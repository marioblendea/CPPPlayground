#include <iostream>

#include "file2.h"
#include "problems/parantheses/parans.h"
#include "problems/printCombinationsOfWordsFromDigitsOnPhone/combinations.h"
#include "problems/LRU/LRU.h"

int main(){
    std::cout << "Hello world! " << f1() << "\n";
    int a;
    std::cin >> a;


    Combinations c;
    c.printWords(L"23");
    std::cout << "\r\n";

    // 
    Parans p(3);
    auto res = p.PrintAll();
    for(auto r: res) {
        std::cout << r << "\r\n";
    }

    // LRU
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

    return 0;
}