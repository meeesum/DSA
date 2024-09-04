#pragma once
template <class T>
class Node
{
public:
    Node<T> *next;
    T value;
    Node();
    Node(T value);
};
template <class T>
class Stack
{
private:
    Node<T> *head;

public:
    Stack();
    ~Stack();
    bool isEmpty();
    T top();
    void push(T value);
    void pop();
    void display();
};