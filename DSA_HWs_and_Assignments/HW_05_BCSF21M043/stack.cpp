#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size)
{
    arr = new int[size];
    capacity = size;
    top = -1;
}

Stack::~Stack()
{
    delete[] arr;
}

void Stack::push(int x)
{
    if (isFull())
    {
        cout << "Stack is full\n";
        return;
    }
    arr[++top] = x;
}

void Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty\n";
        return;
    }
    top--;
}

int Stack::peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty\n";
        return -1;
    }
    return arr[top];
}

int Stack::size()
{
    return top + 1;
}

bool Stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::isFull()
{
    if (top == capacity - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}