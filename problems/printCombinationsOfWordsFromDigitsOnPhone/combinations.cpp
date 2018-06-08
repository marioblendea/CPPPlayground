
#include <iostream>
#include "combinations.h"

using namespace std;

int abc[4][1] = {{0},{0},{0},{0}};

wchar_t matrix[3][3] = {
    {'a', 'b', 'c'}, 
    {'d', 'e', 'f'},
    {'g', 'h', 'i'}};


Combinations::Combinations() {}
Combinations::~Combinations() {}
    
void Combinations::printWords(std::wstring input) {
    std::wstring word;
    printWords(input, word);
}

void Combinations::printWords(std::wstring input, std::wstring word) {
    if (input.empty()) {
        wcout << word << L" ";
        return;
    }

    auto ch = removeFirstChar(input);
    int d = convertCharToDigit(ch) - 2; // 0 and 1 don't have letters in the array
    for(int j = 0; j < 3; j++) {
        std::wstring newWord(word);
        newWord += matrix[d][j];
        printWords(input, newWord);
    }
        
}

wchar_t Combinations::removeFirstChar(std::wstring& input) {
    wchar_t firstChar = input[0];
    input.erase(0, 1);
    return firstChar;
}

int Combinations::convertCharToDigit(wchar_t ch) {
    int dg =  ch - '0';
    if (dg < 2 || dg > 9) throw new std::string("invalid input");
    return dg;
}