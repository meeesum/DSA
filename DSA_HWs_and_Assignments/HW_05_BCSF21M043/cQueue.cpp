#include "cQueue.h"
#include <iostream>
using namespace std;

CircularQueue::CircularQueue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

CircularQueue::~CircularQueue()
{
    delete[] arr;
}

void CircularQueue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue is full\n";
        return;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = x;
    count++;
}

void CircularQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return;
    }
    front = (front + 1) % capacity;
    count--;
}

int CircularQueue::peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return -1;
    }
    return arr[front];
}

int CircularQueue::size()
{
    return count;
}

bool CircularQueue::isEmpty()
{
    if (count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CircularQueue::isFull()
{
    if (count == capacity)
    {
        return true;
    }
    else
    {
        return false;
    }
}