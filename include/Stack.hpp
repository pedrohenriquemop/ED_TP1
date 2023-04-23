#pragma once

#include <iostream>

using namespace std;

template <class T>
class Stack {
   public:
    Stack() {
        top = -1;
        size = 0;
    };

    void push(T item) {
        if (size == MAXTAM)
            throw "Stack is full.";

        top++;
        size++;
        items[top] = item;
    };

    T pop() {
        if (isEmpty())
            throw "Stack is empty.";

        T aux = items[top];
        top--;
        size--;
        return aux;
    };

    T getTop() {
        return items[top];
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void clean() {
        top = -1;
        size = 0;
    };

    void print() {
        for (int i = size - 1; i >= 0; i--) {
            cout << "\t|" << items[i] << endl;
        }
    }

   private:
    int top, size;
    static const int MAXTAM = 1000;
    T items[MAXTAM];
};