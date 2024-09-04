#pragma once
template <class T>
class Node {
    public:
    T value;
    Node<T>* next;
    Node();
    Node(T value);
};
template <class T>
class CSLL1 {
private :
    Node<T>* head;
    Node<T>* tail;
public:
    CSLL1();
    ~CSLL1();
    bool isEmpty();
    Node<T>* findTail();
    void addAtStart(T value);
    void append(T value);
    void addAfter(T value, T valueToBeAdded);
    void addBefore(T value, T valueToBeAdded);
    void deleteNode(T valueToBeDeleted);
    void deleteFromEnd();
    void deleteFromStart();
    void countAllLessThan(T value);
    void deleteKth(T value,int k);
    void display();
};