#include "minHeap.h"

MinHeap::MinHeap(int cap) : size(0), capacity(cap) {
    heap = new int[capacity];
}

MinHeap::~MinHeap() {
    delete[] heap;
}

void MinHeap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void MinHeap::heapifyDown(int index) {
    int leftChild, rightChild, smallest;
    while (index < size) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        smallest = index;

        if (leftChild < size && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < size && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

void MinHeap::insert(int val) {
    if (size == capacity) {
        cout << "Heap is full!" << endl;
        return;
    }
    heap[size] = val;
    size++;
    heapifyUp(size - 1);
}

void MinHeap::deleteMin() {
    if (size == 0) {
        cout << "Heap is empty!" << endl;
        return;
    }
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

int MinHeap::getMin() const {
    if (size == 0) {
        cout << "Heap is empty!" << endl;
        return -1;
    }
    return heap[0];
}

void MinHeap::printHeap() const {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}