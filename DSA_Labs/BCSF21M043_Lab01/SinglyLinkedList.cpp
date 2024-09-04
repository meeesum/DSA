#include <iostream>
#include"SinglyLinkedList.h"
#include <unordered_map>
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
void SinglyLinkedList<T> ::sortedInsertAsc(T value){
	Node<T>* newNode = new Node<T>(value);
		if(isEmpty()){
			head = newNode;
			return;
		}
	Node<T>* temp = head;
	Node<T>* myprev = nullptr;
	while(temp != nullptr){
		if(head->value > value && temp == head){
			addAtStart(value);
			return;
		}
		else{
			if(temp->value > value && temp != head){
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
SinglyLinkedList<T> SinglyLinkedList<T> :: mergetwoSortedList(SinglyLinkedList<T> list1, SinglyLinkedList list2){
	Node<T>* curr1 = list1.head;
	Node<T>* curr2 = list2.head;
	SinglyLinkedList<T> result;
	while(curr1->next != nullptr){
		if(curr1->value > curr2->value){
			addBefore(curr1->value, curr2->value);
			curr2 = curr2->next;
		}
		else if (curr2->value > curr1->value){
			addAfter(curr1->value, curr2->value)
		}
	}
}
template<typename T>
void SinglyLinkedList<T>::removeNthFromEnd(int n) {
	Node<T>* newNode = new Node<T>(n); 
	// Node<T>* temp = head; 
	Node<T>* fast = head; 
	Node<T>* slow = head;
	Node<T>* myprev = nullptr;
	for(int i = 1; i < n; i++){
		fast = fast->next;
	}
	cout<<fast->value<<endl;
	while(fast->next != nullptr){
		fast = fast->next;
		myprev = slow;
		slow = slow->next;
	}
	if(slow == head){
		head = head->next;
		delete slow;
	}
	else{
		myprev->next = slow->next;
		delete slow;
	}
}
template<typename T>
Node<T> SinglyLinkedList<T>:: getNode (int index) {
    Node<T>* current = head;
    int count = 0;
    while (current != nullptr && count < index) {
        current = current->next;
        count++;
    }
    return current;
}
template <class T>
Node<T> SinglyLinkedList<T> :: intersectionPoint(SinglyLinkedList list1, SinglyLinkedList list2){
	Node<T>* temp1 = list1.head;
	Node<T>* temp2 = list2.head;
	T intersectionNode;
	unordered_map<Node<T>*, int> mymap;
	int i = 0;
	while(temp1 != nullptr){
		mymap[temp1] = i;
		temp1 = temp1->next;
		i++;
	}
	while(temp2 != nullptr){
		if(mymap.find(temp2) != mymap.end()){
			cout<<"The intersection point is "<<temp2->value;
			intersectionNode = temp2->value;
			return temp2;
		}
		temp2 = temp2->next;
	}
	return nullptr;
}