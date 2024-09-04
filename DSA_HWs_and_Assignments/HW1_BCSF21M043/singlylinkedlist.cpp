#include <iostream>
#include"SinglyLinkedList.h"
using namespace std;

template <class T>
Node<T> ::Node() {
	this->next = nullptr;
}
template <class T>
Node<T> ::Node(T info) {
	this->value = info;
	this->next = nullptr;
}
template <class T>
SinglyLinkedList <T> ::SinglyLinkedList() {
	this->head = nullptr;

}
template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
	Node<T>* current = head;
	Node<T>* next = nullptr;

	while (current != nullptr) {
		next = current->next;
		delete current;
		current = next;
	}
	delete head;
}
template <class T>
bool SinglyLinkedList<T> ::isEmpty() {
	if (this->head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}
template <class T>
void SinglyLinkedList<T> ::append(T value) {
	Node<T>* temp = head;
	Node<T>* newNode = new Node<T>(value);
	if (isEmpty()) {
		this->head = newNode;
	}
	else {
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = nullptr;
	}
}
template <class T>
void SinglyLinkedList <T> ::addAtStart(T value) {
	Node<T>* newNode = new Node<T>(value);
	newNode->next = head;
	head = newNode;
	
}
template <class T>
void SinglyLinkedList <T> :: addBetween(T value1, T value2, T value3) {
	int flag = 0;
	Node<T>* newNode = new Node<T>(value3);
	Node<T>* temp = head;
	Node<T>* temp1 = new Node<T>;
	while (temp->next != nullptr) {
		if (temp->value == value1 && temp->next->value == value2) {
			flag = 1;
			temp1 = temp->next;
			temp->next = newNode;
			newNode->next = temp1;
		}
		temp = temp->next;
	}
	if (flag == 0) {
		cout << "No such values found in the list!";
	}
}
template <class T>
void SinglyLinkedList<T> :: addAfter(T value) {
	int flag = 0;
	Node<T>* newNode = new Node<T>(value);
	newNode->value = value;
	Node<T>* temp = new Node<T>;
	Node<T>* temp1 = head;
	while (temp1->next != nullptr) {
		if (temp1->value == value) {
			flag = 1;
			temp = head->next;
			temp1->next = newNode;
			newNode->next = temp;
		}
		temp1 = temp1->next;
	}
	if (flag == 0) {
		cout << "No such Value found in the list!";
	}
}
template <class T>
void SinglyLinkedList<T> ::deleteAtStart() {
	if (isEmpty()) {
		cout << "Linked List Already Empty. Delete Action Denied!";
	}
	else {
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
}
template <class T> 
void SinglyLinkedList<T> ::deleteAtEnd() {
	Node<T>* temp = head;
	if (isEmpty()) {
		cout << "Linked List Already Empty. Delete Action Denied!";
	}
	else if (temp->next == nullptr) {
		head = nullptr;
	}
	else {
		Node<T>* current = head;
        int flag = 0;
		while (current->next!= nullptr) {
    	if (current->next->next == nullptr) {
				Node<T>* toBeDeleted = current->next;
                current->next = nullptr;
                delete toBeDeleted;
				toBeDeleted = nullptr;
                flag = 1;
			}
            if(flag!=1){
				current = current->next;
            }
		}
		current->next = nullptr;
		
	}
}
template <class T>
void SinglyLinkedList<T> :: deleteFirst(T value){
	Node<T>* temp = head;
	Node<T>* temp1 = new Node<T>;
	int flag = 0;
	if (isEmpty()) {
		cout << "Linked List Already Empty. Delete Action Denied!";
	}
	else if (temp->value == value) {
		head = head->next;
		delete temp;
	}
	else {
		while (temp->next != nullptr) {
			if (temp->next->value == value) {
				flag = 1;
				temp1 = temp->next;
				temp->next = temp1->next;
				delete temp1;
			}
			temp = temp->next;
		}
		if (flag == 0) {
			cout << "No such value found in the list!";
		}
	}
}
template <class T>
void SinglyLinkedList<T> :: deleteAll(T value) {
	Node<T>* temp = head;
	Node<T>* temp1 = new Node<T>;
	int flag = 0;
	if (isEmpty()) {
		cout << "Linked List Already Empty. Delete Action Denied!";
	}
	else if (temp->value == value) {
		head = head->next;
		delete temp;
	}
	else {
		while (temp->next != nullptr) {
			if (temp->next->value == value) {
				flag = 1;
				temp1 = temp->next;
				temp->next = temp1->next;
				delete temp1;
			}
			temp = temp->next;
		}
		if (flag == 0) {
			cout << "No such value found in the list!";
		}
	}
}
template <class T>
void SinglyLinkedList<T> :: deletekth(T value, int k){
	Node<T>* temp = head;
	Node<T>* temp1 = new Node<T>;
	int flag = 0;
	if (isEmpty()) {
		cout << "Linked List Already Empty. Delete Action Denied!";
	}
	else if (temp->value == value) {
		head = head->next;
		delete temp;
	}
	else {
		int count = 1;
		while (temp->next != nullptr) {
			if (count == k) {
				flag = 1;
				temp1 = temp->next;
				temp->next = temp1->next;
				delete temp1;
			}
			count++;
			temp = temp->next;
		}
		if (flag == 0) {
			cout << "No such value found in the list!";
		}
	}
}
template <class T>
void SinglyLinkedList<T> ::display() const {
	Node<T>* temp = head;
	while (temp != nullptr) {
		cout << temp->value;
		cout << "->";
		temp = temp->next;
	}
	cout << "NULL";
}