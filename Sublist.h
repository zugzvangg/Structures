//
// Created by zugzvangg on 18.02.2020.
//


#ifndef SUBFORWARD_LIST_CLASS_SUBLIST_H
#define SUBFORWARD_LIST_CLASS_SUBLIST_H

#include "Stack.h"
#include <type_traits>
#include <iostream>

class Sublist {
private:

    struct block {
        int data;
        block *next;
    };
    block *head;

    Sublist();

    ~Sublist();

    bool push_back(int d);

    int pop_back();

    bool push_forward(int d);

    int pop_forward();

    bool push_where(unsigned int where, int d);

    bool erase_where(unsigned int where);

    unsigned int size();

    void print();
};


#endif //SUBFORWARD_LIST_CLASS_SUBLIST_H
