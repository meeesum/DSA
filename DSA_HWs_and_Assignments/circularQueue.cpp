#include"circularQueue.h"
#include<iostream>
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
        front->next = newNode;
        front->prev = newNode;
        rear = newNode;
        rear->next = newNode;
        rear->prev = newNode;
    }
    else{
        rear->prev = newNode;
        newNode->next = rear;
        rear = newNode;
        rear->prev = front;
        front->next = rear;
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
        front->next = rear;
        rear->prev = front;
        delete temp;
    }
}
template <class T>
void Queue<T> :: display() const{
    Node<T>* temp = rear;
    do{
        cout<<temp->data <<"->";
        temp = temp->next;
    }while(temp != rear);
}
template <class T>
void Queue<T>::processes() {
    /*I have tried to implement Round Robin Scheduling Algorithm which I had studied in OS course
    basically this program takes intput some processes with their values as burst time and runs the program
    and decrements the timequantum from each processe(nodes)'s value and pops the node whose value reaches 
    0 hence it terminates when all of the processes reach the 0 i.e., they are completely executed 
    it also prints the current state of the queue after processing each node*/
    int timeQuantum = 2;
    while(front != nullptr) {
        front->data -= timeQuantum;
    
        
        this->display();
    
        if (front->data <= 0) {
            Node<T>* temp = front;
            if (front == rear) { 
                front = nullptr;
                rear = nullptr;
            } else {
                front = front->next;
                rear->next = front; 
            }
            delete temp; 
        } else {
            rear->next = front;
            rear = front;
            front = front->next;
            rear->next = nullptr; 
        }
    
        cout << "\n";
        if (front == nullptr) {
            cout << "All processes completed." << endl;
            break;
        }
    
        if (rear != nullptr) {
            rear->next = front;
        }
    }
}
