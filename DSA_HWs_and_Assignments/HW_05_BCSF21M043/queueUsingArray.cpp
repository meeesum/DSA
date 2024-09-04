#include "queueUsingArray.h"
#include <iostream>
using namespace std;
Queue::Queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

Queue::~Queue()
{
    delete[] arr;
}

void Queue::enqueue(int x)
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

void Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return;
    }
    front = (front + 1) % capacity;
    count--;
}

int Queue::peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return -1;
    }
    return arr[front];
}

int Queue::size()
{
    return count;
}

bool Queue::isEmpty()
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

bool Queue::isFull()
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