#include <iostream>
#include "Stack.h"
using namespace std;
template <typename T>

Stack<T>::Stack()
{
    capacity = 10;
    top = -1;
    data = new T[capacity];
}
template <typename T>
void Stack<T>::reSize(int newCapacity)
{
    T *d = new T[newCapacity];
    for (int i = 0; i < capacity; i++)
    {
        d[i] = data[i];
    }
    data = d;
}
template <typename T>
Stack<T>::Stack(const Stack<T> &obj)
{
    capacity = obj.capacity;
    for (int i = 0; i < capacity; i++)
    {
        data[i] = obj.data[i];
    }
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &obj)
{
    capacity = obj.capacity;
    for (int i = 0; i < capacity; i++)
    {
        data[i] = obj.data[i];
    }
}
template <typename T>
T Stack<T>::stackTop() const
{
    return data[top];
}
template <typename T>
bool Stack<T>::isFull() const
{
    if (top == (capacity - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <typename T>
bool Stack<T>::isEmpty() const
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
template <typename T>
int Stack<T>::getCapacity() const
{
    return capacity;
}
template <typename T>
int Stack<T>::getNumberOfElements() const
{
    return (top + 1);
}
template <typename T>
void Stack<T>::push(T element)
{
    if (isFull())
    {
        cout << "Stack is full! Push operation could not be performed.";
        reSize(this->capacity*2);
    }
    else
    {
        data[top++] = element;
    }
}
template <typename T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty! Pop operation could not be performed";
    }
    else
    {
        return (--top);
    }
}
template <typename T>
Stack<T>::~Stack()
{
    delete[] data;
}