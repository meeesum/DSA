#include <iostream>
#include "Queue.h"
using namespace std;
template <typename T>
Queue<T>::Queue()
{
    capacity = 7;
    data = new std:: pair<int, int >[capacity];
    rear = -1;
    front = -1;
}
template <typename T>
Queue<T>::~Queue()
{
    delete[] data;
}
template <typename T>
void Queue<T>::enQueue(T element)
{
    if (isFull())
    {
        reSize(capacity*2);
    }
    else
    {
        data[++rear] = element;
    }
}
template <typename T>
void Queue<T>::deQueue()
{
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    } else {
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}
template <typename T>
bool Queue<T>::isFull()
{
    if (rear == capacity - 1 && front == -1)
        return true;
    else
    {
        return false;
    }
}
template <typename T>
bool Queue<T>::isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <typename T>
T Queue<T>::getElementAtFront()
{
    return data[++front];
}
template <typename T>
int Queue<T>::getNoofElements()
{
    return (capacity - 1);
}
template <typename T>
int Queue<T>::getCapacity()
{
    return capacity;
}
template <typename T>
void Queue<T>::reSize(int newSize)
{
    T *newQueue;
    newQueue = new T[newSize];
    for (int i = 0; i < capacity; i++)
    {
        newQueue[i] = data[i];
    }
    delete[] data;

    data = newQueue;
    capacity = capacity + newSize;
}

