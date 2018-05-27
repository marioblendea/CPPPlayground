#include "parans.h"
#include <stdexcept>

using namespace std;

Parans::Parans(int n) {
    if (n <= 0)
        throw new std::invalid_argument(std::string("invalid input"));

    _n = n;
}

Parans::~Parans() noexcept {}

std::vector<std::string> Parans::PrintAll() {
    std::string curSeq;

    PrintParan(curSeq, 0, 0);
    return _res;
}

void Parans::PrintParan(std::string curSeq, int open, int closed) {
    if (curSeq.length() == _n * 2) {
        _res.push_back(curSeq);
        return;
    }

    if (open < _n)
        PrintParan(curSeq + "(", open + 1, closed);
    if (closed < open )
        PrintParan(curSeq + ")", open, closed + 1);
}