#pragma once
#include <iostream>
using namespace std;

class MinHeap {
private:
    int* heap;
    int size;
    int capacity;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    MinHeap(int cap);
    ~MinHeap();

    void insert(int val);
    void deleteMin();
    int getMin() const;
    void printHeap() const;
};