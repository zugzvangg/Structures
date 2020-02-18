//
// Created by zugzvangg on 18.02.2020.
//

#include "Subvector.h"
#include <iostream>
using namespace std;


Subvector:: Subvector() { //конструктор
    *mas = 0;
    top = 0;
    capacity = 0;
};

Subvector:: ~Subvector() {};

void Subvector:: print() {//вывод в терминал всего вектора
    for (int i = 0; i < top; i++) {
        cout << this->mas[i] << endl;
    }
}

int Subvector:: pop_back() //удаление последнего элемента
{
    int *a = nullptr;
    int i, b;
    b = mas[top - 1];
    a = new int[top - 1];
    for (i = 0; i < (top - 1); i++) {
        a[i] = this->mas[i];
    }
    delete[] this->mas;
    this->mas = a;
    top--;
    capacity = top;
    return b;
}

bool Subvector:: push_back(int a) {//добавление в конец
    int *s1 = nullptr;
    if ((this->top) < (this->capacity)) {
        this->mas[this->top] = a;
        this->top++;
    } else {
        s1 = new int[this->capacity + 1];
        for (i = 0; int i < (this->capacity); i++) {
            s1[i] = this->mas[i];
        }
        delete[] this->mas;
        this->mas = s1;
        this->top++;
        this->capacity++;
        this->mas[this->top - 1] = a;
    }
    if (this->mas == nullptr) return false;
    return true;
}

bool Subvector:: resize(unsigned int new_capacity) {//установка нового размера

    int *a = nullptr;
    a = new int[new_capacity];
    if (this->top <= new_capacity) {
        for (int i = 0; i < top; i++)
            a[i] = this->mas[i];
    } else {
        for (int i = 0; i < new_capacity; i++)
            a[i] = this->mas[i];
        this->top = new_capacity;
    }
    if (this->mas != nullptr) {
        delete[] mas;
    }
    this->mas = a;
    capacity = new_capacity;
    if (mas == nullptr) { return false; }
    return true;
}

void Subvector::shrink_to_fit() {//удаление лишней памяти

    if (this->capacity > this->top) {
        int *a = nullptr;
        a = new int[top];
        for (int i = 0; i < top; i++)
            a[i] = mas[i];
        if (mas != nullptr) {
            delete[] mas;
        }
        this->mas = a;
        this->capacity = this->top;
    }
}

void Subvector::clear() {//очистка памяти
    if (this->mas != nullptr) {
        for (int i = 0; i < this->top; ++i) {
            this->mas[i] = '\0';
        }
    }
    this->top = '\0';
    this->capacity = '\0';
}


