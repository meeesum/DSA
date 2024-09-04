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
void SinglyLinkedList <T> :: addBetween(T value1, T value2, T valueToBeAdded) {
	int flag = 0;
	Node<T>* newNode = new Node<T>(valueToBeAdded);
	Node<T>* temp = head;
	Node<T>* forward = nullptr;
	while(temp!= nullptr || flag !=1){
		if(temp->value == value1 && temp->next->value == value2){
			forward = temp->next;
			temp->next = newNode;
			newNode->next = forward;
			flag = 1;
		}
		forward = temp->next;
	}
	if (flag == 0) {
		cout << "No such values found in the list!";
	}
}
template <class T>
void SinglyLinkedList<T> :: addAfter(T value, T valueToBeAdded) {
	int flag = 0;
	Node<T>* newNode = new Node<T>(valueToBeAdded);
	Node<T>* temp = head;
	Node<T>* forward = nullptr;
	while(temp != nullptr || flag != 1){
		if(temp->value == value){
			forward = temp->next;
			temp->next = newNode;
			newNode->next = forward;
			flag = 1;
		}
		temp = temp->next;
	}
	if(flag == 0){
		cout<<"No such value found in the list!";
	}
}
template <class T>
void SinglyLinkedList <T> :: addBefore(T value,T valueToBeAdded){
	Node<T> * newNode = new Node<T>(valueToBeAdded);
	Node<T>* myprev = nullptr;
	Node<T>* temp = head;
	int flag = 0;
	while(temp != nullptr || flag != 1){
		if(temp->value == value){
		if(temp == head){
			addAtStart(valueToBeAdded);
			flag = 1;
		}
		else{
			myprev->next = newNode;
			newNode->next = temp;
			flag = 1;
		}
		}
			myprev = temp;
			temp = temp->next;

	}
	if(flag == 0){
		cout<<"No such Value found in the list!";
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
void SinglyLinkedList<T> :: deleteFirst(T toBeDeleted){
	Node<T>* temp = head;
	Node<T>* myprev = nullptr;
	int flag = 0;
	if (isEmpty()) {
		cout << "Linked List Already Empty. Delete Action Denied!";
	}

	else {


		while (temp != nullptr && flag != 1) {
			 if (temp->value == toBeDeleted && temp == head) {
			head = head->next;
			delete temp;
			 }

			else if (temp->value == toBeDeleted && temp != head) {
				myprev->next = temp->next;
				delete temp;
				flag = 1;
				return;
			}
			else{
			myprev = temp;
			temp = temp->next;
			}
		}
		if (flag == 0) {
			cout << "No such value found in the list!";
		}
	}
}
template <class T>
void SinglyLinkedList<T> :: deleteAll(T valuetoBeDeleted) {
	if (isEmpty()) {
		cout << "Linked List Already Empty. Delete Action Denied!";
		return;
	}
	Node<T>* temp = head;
	Node<T>* myprev = nullptr;
	int flag = 0;
	int count = 0;
	int i = 0;
	while(temp != nullptr){
		if(temp->value == valuetoBeDeleted){
			count++;
		}
		temp = temp->next;
	}
	temp = head;
		while(i < count && temp != nullptr){
			if(temp->value == valuetoBeDeleted && temp == head){
				head = head->next;
				delete temp;
				temp = head;
				flag = 1;
				i++;
			}
			else if(temp->value == valuetoBeDeleted && temp != head){
				myprev->next = temp->next;
				delete temp;
				temp = myprev->next;
				flag = 1;
				i++;
			}	
			else{
			myprev = temp;
			temp = temp->next;
			}
		}
	if(flag == 0){
		cout<<"No such value found in the list!";
	}
}
template<class T>
void SinglyLinkedList <T> :: deletekth(T valueToBeDeleted, int k){
	Node<T> * temp = head;
	Node<T>* prev = nullptr;
	int count = 0;
	int flag = 0;
	if (isEmpty()){
		cout<<"Linked List Already Empty. Delete Action Denied!";
	}
	else{
	while(temp!= nullptr){
		if(temp->value == valueToBeDeleted){
			count++;
			if(count == k && temp == head){
				flag = 1;
				head = head->next;
				delete temp;
				return;
			}
			else if(count == k && temp!= head){
				flag = 1;
				prev->next = temp->next;
				delete temp;
				return;
			}
		}
			prev = temp;
		    temp = temp->next;
	}
	if(flag == 0){
		cout<<"Kth Occurance not found in the list";
	}
	}
}
template <class T>
void SinglyLinkedList<T> :: reverseList(){
Node<T>* forward = head->next;
Node<T>* curr = head;
Node<T>* prev = nullptr;
if(isEmpty()){
	cout<<"The list is Empty!";
}
else{
	while(forward != nullptr){
		curr->next = prev;
		prev = curr;
		curr = forward;
		forward = forward->next;
	}
	curr->next = prev;
	head = curr;
}
}
template <class T>
int SinglyLinkedList<T> :: length(){
	Node<T>* temp = head;
	int count = 0;
	while(temp != nullptr){
		count++;
		temp = temp->next;
	}
	return count;
}
template<class T>
void SinglyLinkedList<T> :: addTwoNumbers(SinglyLinkedList<T> list1, SinglyLinkedList<T> list2){
	Node<T>* curr1 = list1.head;
	Node<T>* curr2 = list2.head;
	int count1 = list1.length();
	int count2 = list2.length();
	int num1 = 0;
	int num2 = 0;
	int n1 = 1;
	int n2 = 1;
	int i = 0;
	int result;
	while(i < count1 - 1){
		n1 = n1 * 10;
		i++;
	}
	i = 0;
	while(i < count2 - 1){
		n2 = n2 * 10;
		i++;
	}
	while(curr1 != nullptr && n1 >= 1){
		num1 += (curr1->value * n1);
		n1 = n1/10;
		curr1 = curr1->next;
	}
	while(curr2 != nullptr && n2 >= 1){
		num2 += (curr2->value * n2);
		n2 = n2/10;
		curr2 = curr2->next;
	}
	result = num1 + num2;
	cout<<"The result is " <<result;
}
template <class T>
void SinglyLinkedList<T> ::bookSeat(T value){
	Node<T>* newNode = new Node<T>(value);
		if(isEmpty()){
			head = newNode;
			return;
		}
	Node<T>* temp = head;
	Node<T>* myprev = nullptr;
	Node<T>* myforward = temp->next;
	while(temp != nullptr){
		if(head->value > value && temp == head){
			addAtStart(value);
			return;
		}
		else{
			if(temp->value > value && temp != head && myprev->value < value){
				addBefore(temp->value, value);
				return;
			}
			else if(temp->value < value && temp->next == nullptr){
				append(value);
			}
		}
		myprev = temp;
		temp = temp->next;
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
template <class T>
void SinglyLinkedList<T> :: swapNodes(Node<T>* node1, Node<T>* node2){
	Node<T>* temp = nullptr;
	temp = node1->value;
	node1->value = node2->value;
	node2->value = temp;
}
template <class T>
void SinglyLinkedList<T> :: sortAsc(){
	Node<T>* temp = head;
	while(temp != nullptr){
		if(temp->value > temp->next->value){
			swapNodes(temp, temp->next);
		}
		temp = temp->next;
	}
}