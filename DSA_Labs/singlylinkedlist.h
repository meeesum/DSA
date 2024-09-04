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
class SinglyLinkedList{
	Node<T>* head;

public:
	SinglyLinkedList();
	~SinglyLinkedList();
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
	void bookSeat(T value);
	void addTwoNumbers(SinglyLinkedList<T> list1, SinglyLinkedList<T> list2);
	void sortAsc();
	void swapNodes(Node<T> *node1, Node<T>* node2);
	void mergetwoSortedList(SinglyLinkedList<T> list1, SinglyLinkedList<T> list2);
};