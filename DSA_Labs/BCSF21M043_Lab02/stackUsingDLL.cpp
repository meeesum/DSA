#include <iostream>
#include "stackUsingDLL.h"
#include <string.h>
using namespace std;
template <class T>
Node<T>::Node()
{
    this->next = nullptr;
    this->prev = nullptr;
}
template <class T>
Node<T>::Node(T value)
{
    this->next = nullptr;
    this->prev = nullptr;
    this->value = value;
}
template <class T>
Stack<T>::Stack()
{
    head = nullptr;
    top = nullptr;
}
template <class T>
Stack<T>::~Stack()
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
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
T Stack<T>::topOfStack()
{
    return top->value;
}

template <class T>
void Stack<T>::push(T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (isEmpty())
    {
        head = newNode;
        head->prev = nullptr;
        head->next = nullptr;
        top = newNode;
        top->next = nullptr;
    }
    else
    {
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        top->next = nullptr;
    }
}
template <class T>
void Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "The stack is empty\n";
        return;
    }
    else
    {
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            top = nullptr;
            return;
        }
        else
        {
            Node<T> *temp = top;
            top = top->prev;
            delete temp;
            if (top != nullptr)
            {
                top->next = nullptr;
                return;
            }
        }
    }
}
template <class T>
void Stack<T>::display() const
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->value << "->";
        temp = temp->next;
    }
}

template <class T>
void Stack<T>::visitNew(T value, Stack<T>& forward, Stack<T>& back)
{
    this->push(value);
    back.push(this->topOfStack());
    this->push(value);
    cout<<this->topOfStack()<<endl;
}
template <class T>
void Stack<T>::navBack(Stack<T>& forward, Stack<T>& back)
{
    if(back.top == nullptr){
        cout<<"There are no pages to navigate back\n";
    }
    else{
    forward.push(this->topOfStack());
    cout<<"back >> "<<back.topOfStack()<<endl;
    this->push(back.topOfStack());
    back.pop();
    }
}
template <class T>
void Stack<T> :: navForw(Stack<T>& forward, Stack<T>& back){
    if(forward.top == nullptr){
        cout<<"There is no page to forward\n";
    }
    else{
    back.push(this->topOfStack());
    cout<<"forward << "<<forward.topOfStack()<<endl;
    this->push(forward.topOfStack());
    forward.pop();
    }
}
template <class T>
void Stack<T> :: typing(T value, Stack<T>& undo, Stack<T>& redo){
    undo.push(value);
}
template <class T>
void Stack<T> :: undoAction(Stack<T>& undo, Stack<T>& redo){
    if(undo.top == nullptr){
        cout<<"There is no previous action to Undo\n";
    }
    else{
    redo.push(undo.topOfStack());
    cout<<undo.topOfStack()<<endl;
    undo.pop();
    }
}
template <class T>
void Stack<T> :: redoAction(Stack<T>& undo, Stack<T>& redo){
    if(redo.top == nullptr){
        cout<<"There is no action available to redo\n";
    }
    else{
    undo.push(redo.topOfStack());
    cout<<redo.topOfStack()<<endl;
    redo.pop();
    }
}
template <class T>
void Stack<T> :: addTask(T value){
    this->push(value);
    cout<<"Task Added: "<<this->topOfStack()<<endl;
}
template <class T>
void Stack<T> :: completeRecentTask(){
    if(this->top == nullptr){
        cout<<"There are no tasks to complete\n";
    }
    else{
        cout<<"Task Completed:"<< this->topOfStack() <<endl;
        this->pop();
    }
}