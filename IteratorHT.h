#ifndef ADT_SET_ITERATORHT_H
#define ADT_SET_ITERATORHT_H

#include "SetHT.h"
#include <string>

class IteratorHT {
    friend class SetHT;

private:
    const SetHT &table;
    int currentPos;
    explicit IteratorHT(SetHT *newTable);

public:
    ~IteratorHT();
    int getCurrent();
    void next();
    [[nodiscard]] bool valid() const;
};


#endif
