//
// Created by zugzvangg on 18.02.2020.
//

#include "Sublist.h"
#include <iostream>
using namespace std;


Sublist::Sublist()  {//конструктор
    this->head = new block;
    this->head->next = nullptr;
    this->head->data = '\0';
}

Sublist:: ~Sublist() {//деструктор
    block *a = this->head;
    block *b = this->head;
    while (a != nullptr) {
        b = a->next;
        delete a;
        a = b;
    }
}

bool Sublist::push_back(int d) {//добавление в конец
    block *a = this->head;
    if ((a->next == nullptr) && (a->data == '\0')) {
        a->data = d;
        return true;
    } else {
        while (a->next != nullptr) {
            a = a->next;
        }
        a->next = new block;
        a = a->next;
        a->next = nullptr;
        a->data = d;
    }
    return true;
}

int Sublist:: pop_back() {//удаление из конца
    block *a = this->head;
    int d;
    while ((a->next->next) != nullptr) {
        a = a->next;
    }
    delete a->next;
    d = a->data;
    a->next = nullptr;
    return d;
}

bool Sublist:: push_forward(int d) {//добавление в начало
    block *a = new block;
    a->data = d;
    a->next = this->head;
    this->head = a;
    return true;
}

int Sublist:: pop_forward() {//удаление из начала
    block *a = this->head;
    int d;
    d = (this->head)->data;
    this->head = (this->head)->next;
    delete a;
    return d;
}

bool Sublist::push_where(unsigned int where, int d) {//добавление в указанное место
    int s = 1;
    block *a;
    block *b = this->head;
    while (s != where) {
        s++;
        b = b->next;
    }
    a = b->next;
    b->next = new block;
    b->next->next = a;
    b->next->data = b->data;
    b->data = d;
    return true;
}

bool Sublist:: erase_where(unsigned int where) {//удаление изуказанного места
    if (this->head == nullptr) {
        return false;
    }
    int s = 1;
    block *a = this->head;
    block *b = this->head;
    while (s != where) {
        s++;
        b = a;
        a = a->next;
    }
    a = a->next;
    b->next = a;
    return true;
}

unsigned int Sublist::size() {//подсчет размера
    unsigned int a = 0;
    block *b = this->head;
    while (b != nullptr) {
        a++;
        b = b->next;
    }
    return a;
}

void Sublist::print() {//печать
    block *a = this->head;
    while (a != nullptr) {
        cout << a->data << " ";
        a = a->next;
    }
}
