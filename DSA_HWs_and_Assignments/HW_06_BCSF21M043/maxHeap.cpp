#include "maxHeap.h"

MaxHeap::MaxHeap(int cap) : size(0), capacity(cap) {
    heap = new int[capacity];
}

MaxHeap::~MaxHeap() {
    delete[] heap;
}
void MaxHeap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void MaxHeap::heapifyDown(int index) {
    int leftChild, rightChild, largest;
    while (index < size) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        largest = index;

        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

void MaxHeap::insert(int val) {
    if (size == capacity) {
        cout << "Heap is full!" << endl;
        return;
    }
    heap[size] = val;
    size++;
    heapifyUp(size - 1);
}

void MaxHeap::deleteMax() {
    if (size == 0) {
        cout << "Heap is empty!" << endl;
        return;
    }
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

int MaxHeap::getMax() const {
    if (size == 0) {
        cout << "Heap is empty!" << endl;
        return -1;
    }
    return heap[0];
}

void MaxHeap::printHeap() const {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}