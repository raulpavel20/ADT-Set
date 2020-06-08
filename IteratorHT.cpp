#include "IteratorHT.h"

IteratorHT::~IteratorHT() = default;

IteratorHT::IteratorHT(SetHT *newTable) : table(*newTable) {
    this->currentPos = 0;
}

int IteratorHT::getCurrent() {
    return this->table.set[this->currentPos];
}

void IteratorHT::next() {
    if(this->currentPos + 1 <= this->table.length)
        this->currentPos++;
    else throw;
}

bool IteratorHT::valid() const {
    return this->currentPos != this->table.length;
}

