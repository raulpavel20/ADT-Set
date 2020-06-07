#include "SetHT.h"
#include <iostream>

SetHT::SetHT() {
    this->set = new int[20];
    this->next = new int[20];
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
        if(this->firstEmpty == this->hashFunc(elem))
            for(int i = 0; i < this->length; i++)
                if(this->set[i] == 0) {
                    this->firstEmpty = i;
                    break;
                }
    } else {
        this->set[this->firstEmpty] = elem;
        this->next[this->hashFunc(elem)] = this->firstEmpty;
        for(int i = 0; i < this->length; i++)
            if(this->set[i] == 0) {
                this->firstEmpty = i;
                break;
            }
    }
    return true;
}

bool SetHT::remove(int elem) {
    for(int i = 0; i < this->length; i++) {
        if(this->set[i] == elem) {
            this->set[i] = 0;
            if(this->set[this->hashFunc(elem)] != 0)
                this->next[this->hashFunc(elem)] = 0;
            return true;
        }
    }
    return false;
}

bool SetHT::search(int elem) {
    for(int i = 0; i < this->length; i++) {
        if(this->set[i] == elem) {
            return true;
        }
    }
    return false;
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
