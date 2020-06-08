#include "SetHT.h"
#include "IteratorHT.h"

SetHT::SetHT() {
    this->set = new int[20];
    this->next = new int[20];
    for(int i = 0; i < 20; i++)
        this->next[i] = -1;
    this->length = 20;
    this->firstEmpty = 0;
}

SetHT::~SetHT() {
    delete [] this->set;
    delete [] this->next;
}

bool SetHT::add(int elem) {
    bool isFull = true;
    for(int i = 0; i < this->length; i++) {
        if(this->set[i] == 0) isFull = false;
        if(this->set[i] == elem) return false;
    }
    if(isFull) {
        int *newSet = new int[this->length + 20];
        int *newNext = new int[this->length + 20];
        for(int i = 0; i < this->length; i++) {
            newSet[i] = this->set[i];
            newNext[i] = this->next[i];
        }
        this->set = newSet;
        this->next = newNext;
        this->firstEmpty = this->length;
        this->length +=20;
    }
    if(this->set[this->hashFunc(elem)] == 0) {
        this->set[this->hashFunc(elem)] = elem;
        if(this->hashFunc(elem) == this->firstEmpty)
            for(int j = 0; j < this->length; j++)
                if(this->set[j] == 0) {
                    this->firstEmpty = j;
                    break;
                }
        return true;
    }
    int i = this->hashFunc(elem);
    while(this->next[i] != -1)
        i = this->next[i];
    this->set[this->firstEmpty] = elem;
    this->next[i] = this->firstEmpty;
    for(int j = 0; j < this->length; j++)
        if(this->set[j] == 0) {
            this->firstEmpty = j;
            break;
        }
    return true;
}

bool SetHT::remove(int elem) {
    int i = this->hashFunc(elem), prevI = -1;
    while(this->set[i] != elem && i != -1) {
        prevI = i;
        i = this->next[i];
    }
    if(i == -1)
        return false;
    if(this->next[i] != -1) {
        this->set[i] = this->set[this->next[i]];
        this->set[this->next[i]] = 0;
        this->next[this->next[i]] = -1;
        this->next[i] = this->next[this->next[i]];
    } else {
        this->set[i] = 0;
        this->next[prevI] = -1;
    }
    for(int j = 0; j < this->length; j++)
        if(this->set[j] == 0) {
            this->firstEmpty = j;
            break;
        }
    return true;
}

bool SetHT::search(int elem) {
    int i = this->hashFunc(elem);
    while(this->set[i] != elem && i != -1) {
        i = this->next[i];
    }
    return this->set[i] == elem;
}

int SetHT::size() {
    int size = 0;
    for(int i = 0; i < this->length; i++)
        if(this->set[i] != 0) size++;
    return size;
}

bool SetHT::isEmpty() {
    for(int i = 0; i < this->length; i++)
        if(this->set[i] != 0) return false;
    return true;
}

IteratorHT SetHT::iterator() {
    return IteratorHT(this);
}
