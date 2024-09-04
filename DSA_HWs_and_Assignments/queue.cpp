#include<iostream>
#include "queue.h"
using namespace std;
template <class T>
Node<T> :: Node(){
    this->next = nullptr;
    this->prev = nullptr;
}
template <class T>
Node<T> :: Node(T value){
    this->next = nullptr;
    this->prev = nullptr;
    this->data = value;
}
template <class T>
Queue<T> :: Queue(){
    this->front = nullptr;
    this->rear = nullptr;
}
template <class T>
Queue<T> :: ~Queue(){
    do{
        deQueue();
    }while(this->rear != front);
}
template <class T>
void Queue<T> :: enQueue(T value){
    Node<T>* newNode = new Node<T>(value);
    if(this->front == nullptr){
        front = newNode;
        rear = newNode;
    }
    else{
        rear->prev = newNode;
        newNode->next = rear;
        rear = newNode;
    }
}
template <class T>
void Queue<T> :: deQueue(){
    if(this->front == nullptr){
        cout<<"Queue is empty\n";
    }
    else{
        Node<T>* temp = front;
        front = front->prev;
        front->next = nullptr;
        delete temp;
    }
}
template <class T>
void Queue<T> :: display() const{
    Node<T>* temp = rear;
    while(temp != nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}
template <class T>
bool Queue<T> :: isEmpty(){
if(this->front == nullptr){
    return true;
}
else{
    return false;
}
}