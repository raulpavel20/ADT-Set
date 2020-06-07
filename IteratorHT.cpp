#include "IteratorHT.h"

IteratorHT::~IteratorHT() = default;

IteratorHT::IteratorHT(const SetHT& newTable) {
    this->table = newTable;
    this->currentPos = 0;
}

int IteratorHT::getCurrent() {
    return this->table.set[this->currentPos];
}

void IteratorHT::next() {
    if(this->currentPos + 1 <= this->table.length)
        this->currentPos++;
    else throw std::string("out of bounds");
}

bool IteratorHT::valid() {
    return this->table.set[this->currentPos] != 0;
}

