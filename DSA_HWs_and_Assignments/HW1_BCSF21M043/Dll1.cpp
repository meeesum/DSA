#include<iostream>
#include"Dll1.h"
using namespace std;
template <class T>
Node <T> ::Node() {
    this->prev = nullptr;
    this->next = nullptr;
}
template <class T>
Node <T> ::Node (T info) {
    this->value = info;
    this->prev = nullptr;
    this->next = nullptr;
}
template <class T>
DoublyLinkedList<T> ::DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
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
bool DoublyLinkedList<T> ::isEmpty() {
    if (this->head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}
template <class T>
void DoublyLinkedList<T> ::append(T value) {
    Node<T>* temp = head;
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        this->head = newNode;
        this->tail = newNode;
    }
    else {
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = nullptr;
        tail = newNode;
    }
}
template <class T>
void DoublyLinkedList <T> ::addAtStart(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
    head->prev = nullptr;
}
template <class T>
void DoublyLinkedList <T> ::addBetween(T value1, T value2, T value3) {
    Node<T>* temp = head;
    Node<T>* newNode = new Node<T>(value2);
    while (temp->value != value1) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next->prev = newNode;
}
template <class T>
void DoublyLinkedList <T> ::addAfter(T value) {
    Node<T>* temp = head;
    Node<T>* newNode = new Node<T>(value);
    while (temp->value != value) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next->prev = newNode;
}
template <class T>
void DoublyLinkedList <T> ::addBefore(T value) {
    Node<T>* temp = head;
    Node<T>* newNode = new Node<T>(value);
    while (temp->next->value != value) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next->prev = newNode;
}
template <class T>
void DoublyLinkedList <T> ::deleteAtStart() {
    Node<T>* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
}
template <class T>
void DoublyLinkedList <T> ::deleteAtEnd() {
    Node<T>* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    tail = temp;
}
template <class T>
void DoublyLinkedList <T> ::deleteFirst(T value) {
    Node<T>* temp = head;
    while (temp->next->value != value) {
        temp = temp->next;
    }
    Node<T>* temp1 = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete temp1;
}
template <class T>
void DoublyLinkedList <T> ::deleteAll(T value) {
    Node<T>* temp = head;
    while (temp->next != nullptr) {
        if (temp->next->value == value) {
            Node<T>* temp1 = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            delete temp1;
        }
        temp = temp->next;
    }
}
template <class T>
void DoublyLinkedList <T> ::display() const {
    Node<T>* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
}
template <class T>
void DoublyLinkedList <T> ::deletekth(T value, int k) {
    Node<T>* temp = head;
    int count = 1;
    while (temp->next != nullptr) {
        if (count == k) {
            Node<T>* temp1 = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            delete temp1;
        }
        count++;
        temp = temp->next;
    }
}

