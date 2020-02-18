//
// Created by zugzvangg on 18.02.2020.
//

#ifndef SUBFORWARD_LIST_CLASS_STACK_H
#define SUBFORWARD_LIST_CLASS_STACK_H


class Stack {
protected:
public:
    virtual bool push_back(int d) = 0;

    virtual int pop_back() = 0;

    virtual void print() = 0;

};


#endif //SUBFORWARD_LIST_CLASS_STACK_H
