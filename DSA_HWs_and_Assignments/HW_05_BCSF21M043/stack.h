#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size = 10);
    ~Stack();

    void push(int x);
    void pop();
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

#endif // STACK_H