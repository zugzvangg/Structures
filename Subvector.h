//
// Created by zugzvangg on 18.02.2020.
//

#ifndef SUBFORWARD_LIST_CLASS_SUBVECTOR_H
#define SUBFORWARD_LIST_CLASS_SUBVECTOR_H

#include "Stack.h"
#include <type_traits>
#include <iostream>

using namespace std;

class Subvector {

private:
    int *mas;
    unsigned int top;
    unsigned int capacity;
public:

    Subvector();

    ~Subvector();

    int pop_back();

    bool resize(unsigned int new_capacity);

    void shrink_to_fit();

    void clear();

    void print();

    bool push_back(int a);

};


#endif //SUBFORWARD_LIST_CLASS_SUBVECTOR_H
