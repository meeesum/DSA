#pragma once

class Queue {
public:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

    Queue(int size = 10);
    ~Queue();

    void enqueue(int x);
    void dequeue();
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};
