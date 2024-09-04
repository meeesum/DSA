#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;
template <class T>
Node<T>::Node()
{
    this->prev = nullptr;
    this->next = nullptr;
}
template <class T>
Node<T>::Node(T info)
{
    this->value = info;
    this->prev = nullptr;
    this->next = nullptr;
}
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node<T>* temp = head;
    while (head != nullptr)
    {
        head = head->next;
        delete temp;
    }
}
template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
void DoublyLinkedList<T>::append(T value)
{
    Node<T>* newNode = new Node<T>(value);
    Node<T>* temp = head;
    if (isEmpty())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
template <class T>
void DoublyLinkedList<T>::addAtStart(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
template <class T>
void DoublyLinkedList<T> ::addBefore(T value, T valueToBeAdded) {
    Node<T>* newNode = new Node<T>(valueToBeAdded);
    Node<T>* temp = head;
    Node<T>* myprev = nullptr;
    int flag = 0;
    while (temp != nullptr && flag != 1) {
        if (temp->value == value) {
            myprev = temp->prev;
            myprev->next = newNode;
            temp->prev = newNode;
            newNode->prev = myprev;
            newNode->next = temp;
            flag = 1;
            return;
        }
        temp = temp->next;
    }
}
template <class T>
void DoublyLinkedList<T> ::addAfter(T value, T valueToBeAdded) {
    Node<T>* newNode = new Node<T>(valueToBeAdded);
    Node<T>* temp = head;
    Node<T>* forward = nullptr;
    int flag = 0;
    while (temp != nullptr && flag != 1) {
        if (temp->value == value) {
            forward = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = forward;
            flag = 1;
            return;
        }
        temp = temp->next;
    }
    if (flag == 0) {
        cout << "No such value found! Delete Action Denied!";
    }
}
template <class T>
void DoublyLinkedList<T> :: addBetween(T value1, T value2, T valueToBeAdded) {
    Node<T>* newNode = new Node<T>(valueToBeAdded);
    Node<T>* temp = head;
    Node<T>* forward = nullptr;
    int flag = 0;
    while (temp!= nullptr && flag!= 1) {
        if (temp->value == value1 && temp->next->value == value2) {
            forward = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = forward;
            flag = 1;
            return;
        }
    }
        if (flag == 0) {
            cout << "No such values found! Delete Action Denied!";
        }
}
template <class T>
void DoublyLinkedList<T> ::deleteAtStart() {
    Node<T>* temp = head;
    if (isEmpty()) {
        cout << "The list is empty! Cannot Delete!";
    }
    else {
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
}
template <class T>
void DoublyLinkedList<T> ::deleteAtEnd() {
    Node<T>* temp = head;
    Node<T>* prev = nullptr;
    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = nullptr;
}
template <class T>
void DoublyLinkedList<T> ::deleteFirst(T toBeDeleted) {
    Node<T>* temp = head;
    Node<T>* myprev = nullptr;
    Node<T>* forward = nullptr;
    int flag = 0;
    while (temp != nullptr && flag != 1) {
        if (temp->value == toBeDeleted && temp == head) {
            deleteAtStart();
            return;
        }
        else if (temp->value == toBeDeleted && temp->next == nullptr) {
            deleteAtEnd();
            return;
        }
        else if(temp->value == toBeDeleted && (temp != head && temp->next != nullptr)){
            myprev = temp->prev;
            forward = temp->next;
            myprev->next = forward;
            forward->prev = myprev;
            delete temp;
            return;
        }
        else {
        temp = temp->next;
        }
    }
    if (flag == 0) {
        cout << "No such value found in the list!";
    }
}
template <class T>
void DoublyLinkedList<T> :: display() const{
    Node<T>* temp = head;
    while (temp != nullptr) {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "Null";
}
template <class T>
void DoublyLinkedList<T> ::deleteAll(T valueToBeDeleted) {
    Node<T>* temp = head;
    Node<T>* myprev = nullptr;
    Node<T>* forward = nullptr;
    int flag = 0;
    while (temp != nullptr) {
        if (temp->value == valueToBeDeleted && temp == head) {
            head = head->next;
            head->prev = nullptr;
            temp = head;
            flag = 1;
        }
        else if (temp->value == valueToBeDeleted && temp->next == nullptr) {
            myprev = temp->prev;
            myprev->next = nullptr;
            delete temp;
            flag = 1;
            return;
        }
        else if (temp->value == valueToBeDeleted && temp != head && temp->next != nullptr) {
            myprev = temp->prev;
            forward = temp->next;
            myprev->next = forward;
            forward->prev = myprev;
            temp = forward;
        }
        else {
        temp = temp->next;
        }
    }
}
template <class T>
void DoublyLinkedList<T> ::deletekth(T valueToBeDeleted, int k) {
    Node<T>* temp = head;
    Node<T>* myprev = nullptr;
    Node<T>* forward = nullptr;
    int count = 0;
    while (temp != nullptr) {
        if (temp->value == valueToBeDeleted) {
            count++;
            if (count == k && temp == head) {
                deleteAtStart();
                return;
            }
            else if (count == k && temp->next == nullptr) {
                deleteAtEnd();
                return;
            }
            else if (count == k && temp->next != nullptr && temp != head) {
                myprev = temp->prev;
                forward = temp->next;
                myprev->next = forward;
                forward->prev = myprev;
                delete temp;
                return;
            }
        }
        temp = temp->next;
    }
}

template<typename T>
DoublyLinkedList<T> DoublyLinkedList<T> :: addTwoNumbers(DoublyLinkedList<T> list1, DoublyLinkedList<T> list2) {
    DoublyLinkedList<T> result;
    Node<T>* node1 = list1.head;
    Node<T>* node2 = list2.head;
    while (node1->next != nullptr) {
        node1 = node1->next;
    }
    while (node2->next != nullptr) {
        node2 = node2->next;
    }

    T carry = 0;

    while (node1 != nullptr || node2 != nullptr) {
        T sum = carry;
        if (node1 != nullptr) {
            sum += node1->value;
            node1 = node1->prev; 
        }
        if (node2 != nullptr) {
            sum += node2->value;
            node2 = node2->prev; 
        }
        carry = sum / 10;
        T digit = sum % 10;
        result.addAtStart(digit); 
    }

    if (carry > 0) {
        result.addAtStart(carry);
    }

    return result;
}
template <class T>
Node<T> DoublyLinkedList<T> :: getNode(T value){
    Node<T>* temp = this->head;
    while(temp != nullptr){
        if(temp->value == value){
            return *temp;
        }
    }
}
