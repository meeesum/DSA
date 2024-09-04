#pragma once
template <typename T>
class Stack
{
private:
    T *data;
    int capacity;
    int top;
    void reSize(int newCapacity);

public:
    Stack();
    Stack(const Stack<T> &obj);
    Stack &operator=(const Stack<T> &obj);
    ~Stack();
    T stackTop() const;
    bool isFull() const;
    bool isEmpty() const;
    int getCapacity() const;
    int getNumberOfElements() const;
    void push(T element);
    T pop();
};