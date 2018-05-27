// given a number N, print all valid combinations of N open/closed paranthesis
#pragma once
#include <vector>
#include <string>

class Parans {
    public:
        Parans(int n);
        virtual ~Parans() noexcept;

        std::vector<std::string> PrintAll();

    private:
        void PrintParan(std::string curSeq, int open, int closed);

        int _n;
        std::vector<std::string> _res;
};