#include <iostream>
#include "priorityQueue.h"
using namespace std;
template <class T>
Node<T>::Node()
{
    this->data = 0;
    this->priority = 0;
    this->next = nullptr;
    this->prev = nullptr;
}
template <class T>
Node<T>::Node(T data, int priority)
{
    this->data = data;
    this->priority = priority;
    this->next = nullptr;
    this->prev = nullptr;
}
template <class T>
PQueue<T>::PQueue()
{
    this->front = nullptr;
    this->rear = nullptr;
}
template <class T>
PQueue<T>::~PQueue()
{
    while (front != NULL)
    {
        Node<T> *temp = front;
        front = front->next;
        delete temp;
    }
}
template <class T>
bool PQueue<T>::isEmpty()
{
    if (front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
void PQueue<T>::enQueue(T data, int priority)
{
    Node<T> *newNode = new Node<T>(data, priority);
    if (front == NULL)
    {
        front = rear = newNode;
    }
    else if (front->priority > priority)
    {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    else if (rear->priority <= priority)
    {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
    else
    {
        Node<T> *temp = front;
        while (temp->next->priority <= priority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
}
template <class T>
void PQueue<T>::deQueue()
{
    if (front == NULL)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        Node<T> *temp = front;
        front = front->next;
        delete temp;
    }
}
template <class T>
void PQueue<T>::display() const
{
    Node<T> *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
template <class T>
void PQueue<T> :: addTask(const T &item)
{
    this->enQueue(item);
}
template <class T>
void PQueue<T> :: addJob(const T &job)
{
    addTask(job);
}
template <class T>
void PQueue<T> :: processJobs()
{
    while (!isEmpty())
    {
        T job = this->front->data;
        deQueue();
        cout << "Printing: " << job.description << " with priority " << job.priority << endl;
    }
}