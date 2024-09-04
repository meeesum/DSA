#pragma once

#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* heap;
    int size;
    int capacity;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    MaxHeap(int cap);
    ~MaxHeap();

    void insert(int val);
    void deleteMax();
    int getMax() const;
    void printHeap() const;
};
