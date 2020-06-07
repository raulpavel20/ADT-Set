#ifndef ADT_SET_ITERATORHT_H
#define ADT_SET_ITERATORHT_H

#include "SetHT.h"
#include <string>

class IteratorHT {
    friend class SetHT;

private:
    SetHT table;
    int currentPos;
    explicit IteratorHT(const SetHT& newTable);

public:
    ~IteratorHT();
    int getCurrent();
    void next();
    bool valid();
};


#endif
