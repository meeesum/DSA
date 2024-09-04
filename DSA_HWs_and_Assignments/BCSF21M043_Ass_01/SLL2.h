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
class SLL2{
	Node<T>* head;
    Node<T>* tail;
public:
	SLL2();
	~SLL2();
	void append(T value);
	void addAtStart(T value);
	void addBefore(T value, T valueToBeAdded);
	void addAfter(T value, T valueToBeAdded);
	void deleteAtStart();
	void deleteAtEnd();
	void deleteFirstOccurance(T toBeDeleted);
	void deleteAllOccurances(T value);
	void display() const;
	void deletekthOccurance(T value, int k);
    int countAllLessThanValue(T value);
	bool isEmpty();
};