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
	void addBefore(T value, T valueToBeAdded);
	void addAfter(T value, T valueToBeAdded);
	void deleteAtStart();
	void deleteAtEnd();
	void deleteFirst(T toBeDeleted);
	void deleteAll(T value);
	void display() const;
	void deletekth(T value, int k);
	void reverseList();
	bool isEmpty();
	int length();
	void sortedInsertAsc(T value);
	void sortedInsertDsc(T value);
	void addTwoNumbers(SinglyLinkedList<T> list1, SinglyLinkedList<T> list2);
	void sortAsc();
	void swapNodes(Node<T> *node1, Node<T>* node2);
	
};