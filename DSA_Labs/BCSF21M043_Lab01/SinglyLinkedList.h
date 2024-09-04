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
	void display() const;
	void reverseList();
	bool isEmpty();
	int length();
	void sortedInsertAsc(T value);
	void addTwoNumbers(SinglyLinkedList<T> list1, SinglyLinkedList<T> list2);
	SinglyLinkedList<T> mergetwoSortedList(SinglyLinkedList<T> list1, SinglyLinkedList<T> list2);
	void removeNthFromEnd(int n);
	Node<T> getNode(int index);
	Node<T> intersectionPoint(SinglyLinkedList list1, SinglyLinkedList list2);
};