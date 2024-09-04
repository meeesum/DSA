#pragma once
template <typename T>
class Queue
{
private:
    int rear;
    int front;
    int capacity;
    int noOfElements;
    T *data;
    void reSize(int newSize);

public:
    Queue();
    ~Queue();
    void enQueue(T);
    void deQueue();
    T getElementAtFront();
    bool isEmpty();
    bool isFull();
    int getNoofElements();
    int getCapacity();
};
