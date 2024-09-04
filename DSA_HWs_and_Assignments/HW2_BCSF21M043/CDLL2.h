#pragma once
template <class T>
class Node{
public:
    T value;
    Node<T>* next;
    Node<T>* prev;
    Node();
    Node(T value);
};
template <class T>
class CDLL2{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    CDLL2();
    ~CDLL2();
    bool isEmpty();
    void addAtStart(T value);
    void append(T value);
    void addAfter(T value, T valueToBeAdded);
    void addBefore(T value, T valueToBeAdded);
    void deleteFromEnd();
    void deleteFromStart();
    void countAllLessThan(T value);
    void deleteKth(T value,int k);
    void display();
};