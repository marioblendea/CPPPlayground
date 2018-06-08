// Given a string with characters between 2 and 9, print all the words that can be formed if the numbers represent keys on a phone
#pragma once
#include <string>

class Combinations {
    public:
        Combinations();
        virtual ~Combinations();
    
        void printWords(std::wstring input);

    private:
        void printWords(std::wstring input, std::wstring word);

        wchar_t removeFirstChar(std::wstring& input);

        int convertCharToDigit(wchar_t ch);
};