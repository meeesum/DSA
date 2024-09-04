#pragma once
class CircularQueue {
private:
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    CircularQueue(int size);
    ~CircularQueue();
    void enqueue(int x);
    void dequeue();
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

