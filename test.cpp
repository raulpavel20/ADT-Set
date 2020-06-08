#include "test.h"

void runTests() {
    testAdd();
    testRemove();
    testSize();
    testSearch();
    testEmpty();

    testCurrentNext();
}

void testAdd() {
    auto set = new SetHT();
    assert(set->add(123));
    assert(!set->add(123));
    assert(set->add(143));
    assert(!set->add(143));
    assert(set->add(223));
    assert(!set->add(223));
}

void testRemove() {
    auto set = new SetHT();
    set->add(123);
    set->add(223);
    assert(set->remove(123));
    assert(set->remove(223));
    assert(!set->remove(323));
}

void testSize() {
    auto set = new SetHT();
    set->add(123);
    assert(set->size() == 1);
    set->add(223);
    assert(set->size() == 2);
}

void testSearch() {
    auto set = new SetHT();
    set->add(123);
    assert(set->search(123));
    assert(!set->search(223));
    set->add(223);
    assert(set->search(123));
    assert(set->search(223));
}

void testEmpty() {
    auto set = new SetHT();
    assert(set->isEmpty());
    set->add(123);
    assert(!set->isEmpty());
}

void testCurrentNext() {
    auto set = new SetHT();
    set->add(20);
    set->add(41);
    auto it = set->iterator();
    assert(it.getCurrent() == 20);
    it.next();
    assert(it.getCurrent() == 41);
}