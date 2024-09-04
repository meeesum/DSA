#include "stackUsingSLL1.h"
#include <iostream>
using namespace std;
template <class T>
Node<T>::Node()
{
    this->next = nullptr;
}
template <class T>
Node<T>::Node(T value)
{
    this->next = nullptr;
    this->value = value;
}
template <class T>
Stack<T>::Stack()
{
    this->head = nullptr;
}
template <class T>
Stack<T>::~Stack()
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        Node<T> *next = temp->next;
        delete temp;
        temp = next;
    }
}
template <class T>
bool Stack<T>::isEmpty()
{
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
void Stack<T>::push(T value)
{
    Node<T> *newNode = new Node<T>(value);
    Node<T> *temp = head;
    if (isEmpty())
    {
        head = newNode;
    }
    else
    {
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = nullptr;
    }
}
template <class T>
T Stack<T> :: top(){
    Node<T>* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    return temp->value;
}
template <class T>
void Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "The Stack is empty\n";
    }
    else
    {
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        else
        {
            Node<T> *temp = head;
            Node<T> *forward = head->next;
            while (forward->next != nullptr)
            {
                temp = temp->next;
                forward = forward->next;
            }
            delete forward;
            forward = nullptr;
            temp->next = nullptr;
        }
    }
}
template <class T>
void Stack<T>::display()
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "NULL";
}