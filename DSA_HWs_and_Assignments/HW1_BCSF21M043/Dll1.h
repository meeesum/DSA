#pragma once
template <class T>
class Node {
	public:
	T value;
    Node<T>* prev;
	Node<T>* next;
    Node();
    Node(T value);

};
template <class T>
class DoublyLinkedList{
    Node<T>* head;
    Node<T>* tail;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void append(T value);
    void addAtStart(T value);
    void addBetween(T value1, T value2, T value3);
    void addAfter(T value);
    void addBefore(T value);
    void deleteAtStart();
    void deleteAtEnd();
    void deleteFirst(T value);
    void deleteAll(T value);
    void display() const;
    void deletekth(T value, int k);
    bool isEmpty();
};