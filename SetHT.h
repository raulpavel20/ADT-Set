#ifndef ADT_SET_SETHT_H
#define ADT_SET_SETHT_H


class SetHT {
private:
    int *set;
    int *next;
    int length;
    int firstEmpty;
    [[nodiscard]] int hashFunc(int elem) const { return elem % this->length; }

public:
    SetHT();
    ~SetHT();

    bool add(int elem);
    bool remove(int elem);
    bool search(int elem);
    int size();
    bool isEmpty();
};


#endif
