#include<iostream>
#include "CDLL2.h"
using namespace std;
template <class T>
Node<T> :: Node(){
    this->next = nullptr;
    this->prev = nullptr;
}
template <class T>
Node<T>::Node(T value) {
    this->value = value;
    this->next = this;
    this->prev = this; 
}
template <class T>
CDLL2<T> :: CDLL2(){
    this->head = nullptr;
    this->tail = nullptr;
}
template <class T>
CDLL2<T>::~CDLL2() {
    if (head == nullptr) {
        return; 
    }
    Node<T>* temp = head;
    do {
        Node<T>* nextptr = temp->next;
        delete temp;
        temp = nextptr;
    } while (temp != head);

    head = nullptr;
    tail = nullptr;
}
template <class T>
bool CDLL2<T> :: isEmpty(){
    if(this->head == nullptr){
        return true;
    }
    else{
        return false;
    }
}
template <class T>
void CDLL2<T> :: addAtStart(T value){
    Node<T>* newNode = new Node<T>(value);
    Node<T>* temp = head;
    if(isEmpty()){
        this->head = newNode;
        this->tail = newNode;
        newNode->next = head;
        newNode->prev = head;
    }
    else{
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = tail;
        tail->next = newNode;
        head = newNode;
    }
}
template <class T>
void CDLL2<T> :: append(T value){
    Node<T>* newNode = new Node<T>(value);
    Node<T>* temp = head;
    if(isEmpty()){
        this->head = newNode;
        this->tail = newNode;
        newNode->next = head;
        newNode->prev = head;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail = newNode;
    }
}
template <class T>
void CDLL2<T> :: addAfter(T value, T valueToBeAdded){
    int flag = 0;
    Node<T>* newNode = new Node<T>(valueToBeAdded);
    Node<T>* temp = head;
    if(isEmpty()){
        this->head = newNode;
        this->tail = newNode;
        newNode->next = head;
        newNode->prev = head;
        flag = 1;
    }
    else{
        while(temp->next != head){
            if(temp->value == value){
                flag = 1;
                temp->next = newNode;
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                return;
            }
            else{
            temp = temp->next;
            }
        }
        if(temp->value == value && temp == tail){
            flag = 1;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }
    if(flag == 0){
        cout<<"Value not found"<<endl;
        return;
    }
}
template <class T>
void CDLL2<T> :: addBefore(T value, T valueToBeAdded){
    int flag = 0;
    Node<T>* newNode = new Node<T>(valueToBeAdded);
    Node<T>* temp = head;
    Node<T>* myprev = head;
    while(temp->next != head){
        if(temp->value == value){
            if(temp == head){
                newNode->next = head;
                head->prev = newNode;
                newNode->prev = tail;
                tail->next = newNode;
                head = newNode;
                flag = 1;
                return;
            }
            else{
                myprev->next = newNode;
                newNode->prev = myprev;
                newNode->next = temp;
                temp->prev = newNode;
                flag = 1;
                return;
            }
        }
        myprev = temp;
        temp = temp->next;
    }
    if(flag == 0){
        cout<<"Value not found"<<endl;
    }
}
template <class T>
void CDLL2<T> :: deleteFromEnd(){
    Node<T>* temp = tail;
    Node<T>* myprev = tail->prev;
    if(isEmpty()){
        cout<<"List is Empty!\n";
        return;
    }
    else if(head->next == head){
        delete head;
        head = nullptr;
    }
    else{
        myprev->next = head;
        tail = myprev;
        head->prev = tail;
        delete temp;
    }
}
template <class T>
void CDLL2<T> :: deleteFromStart(){
    Node<T>* temp = head;
    if(isEmpty()){
        cout<<"The list is empty!\n";
        return;
    }
    else if(temp->next == head){
        delete head;
        head = nullptr;
    }
    else{
        head = temp->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }
}
template <class T>
void CDLL2<T> :: deleteKth(T value, int k){
    Node<T>* temp = head;
    Node<T>* myprev = tail;
    Node<T>* forward = nullptr;
    int count = 0;
    int flag = 0;
    while(temp->next != head){
        if(temp->value == value){
            count++;
            if(count == k){
                flag = 1;
                if(temp == head){
                    head = head->next;
                    head->prev = tail;
                    tail->next = head;
                    delete temp;
                    return;
                }
                else{
                    myprev->next = temp->next;
                    temp->next->prev = myprev;
                    delete temp;
                    return;
                }
            }
        }
        myprev = temp;
        temp = temp->next;
    }
    if(temp->value == value){
        count++;
        if(count == k){
            flag = 1;
            deleteFromEnd();
            return;
        } 
    }
    if(flag == 0){
        cout<<"Value not found\n";
    }
}
template<class T>
void CDLL2<T> :: countAllLessThan(T value){
    Node<T>* temp = head;
    int flag = 0;
    int count = 0;
    if(isEmpty()){
        cout<<"List is empty!\n";
        return;
    }
    else{
        while(temp->next != head){
            if(temp->value < value){
                flag = 1;
                count++;
            }
            temp = temp->next;
        }
    }
    if(temp->value < value){
        flag = 1;
        count++;
    }
    if(flag == 0){
        cout<<"No value less than "<<value<<endl;
    }
    else{
        cout<<"Number of values less than "<<value<<" are: "<<count<<endl;
    }
}
template<class T>
void CDLL2<T> :: display(){
    Node<T>* temp = head;
    while(temp->next != head){
        cout<<temp->value <<"->";
        temp = temp->next;
    }
    cout<<temp->value;
}