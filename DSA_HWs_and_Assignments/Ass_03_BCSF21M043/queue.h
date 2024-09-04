#pragma once
template <class T>
class Node{
    public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node();
    Node(T data);
};
template <class T>
class Queue{
    private:
    Node<T>* front;
    Node<T>* rear;
    public:
    Queue();
    ~Queue();
    bool isEmpty();
    void enQueue(T data);
    void deQueue();
    void display() const;
    T front();
    int size();
};