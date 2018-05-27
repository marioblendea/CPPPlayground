// Given a string with characters between 2 and 9, print all the words that can be formed if the numbers represent keys on a phone
#pragma once
#include <string>

class Combinations {
    public:
        Combinations();
        virtual ~Combinations();
    
        void printWords(std::string input);

    private:
        void printWords(std::string input, std::string word);

        wchar_t removeFirstChar(std::string& input);

        int convertCharToDigit(wchar_t ch);
};