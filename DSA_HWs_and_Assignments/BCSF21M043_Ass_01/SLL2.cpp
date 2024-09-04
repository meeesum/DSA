#include<iostream>
#include"SLL2.h"
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
SLL2 <T> ::SLL2() {
    this->head = nullptr;
    this->tail = nullptr;
}
template <class T>
SLL2 <T>::~SLL2() {
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
bool SLL2<T> :: isEmpty() {
    if (head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}
template <class T>
void SLL2<T> :: append(T value){
    Node<T>* temp = head;
    Node<T>* newNode = new Node<T>(value);
    if(isEmpty()){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}
template <class T>
void SLL2<T> :: addAtStart(T value){
    Node<T>* newNode = new Node<T>(value);
    if(isEmpty()){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}
template <class T>
void SLL2<T> :: addBefore(T value, T valueToBeAdded){
    Node<T>* temp = head;
    Node<T>* newNode = new Node<T>(valueToBeAdded);
    if(isEmpty()){
        cout<<"List is empty"<<endl;
    }
    else if(head->value == value){
        addAtStart(valueToBeAdded);
    }
    else{
        while(temp->next != nullptr){
            if(temp->next->value == value){
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
    }
}
template <class T>
void SLL2<T> :: addAfter(T value, T valueToBeAdded){
    Node<T>* temp = head;
    Node<T>* newNode = new Node<T>(valueToBeAdded);
    int flag = 0;
    if(isEmpty()){
        cout<<"List is Empty\n";
    }
    else{
        while(temp != nullptr){
            if(temp->value == value){
                flag = 1;
                if(temp == tail){
                    temp->next = newNode;
                    tail = newNode;
                    return;
                }
                else{
                    temp->next = newNode;
                    newNode->next = temp->next->next;
                    return;
                }
            }
            temp = temp->next;
        }
    }
    if(flag == 0){
        cout<<"Value not found in the list\n";
    }
}
template <class T>
void SLL2<T> :: deleteAtStart(){
    if(isEmpty()){
        cout<<"List is empty\n";
    }
    else{
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}
template <class T>
void SLL2<T> :: deleteAtEnd(){
    if(isEmpty()){
        cout<<"List is empty\n";
    }
    else{
        Node<T>* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;
}
}
template <class T>
void SLL2<T> :: deleteFirstOccurance(T toBeDeleted){
    if(isEmpty()){
        cout<<"List is empty\n";
    }
    else{
        Node<T>* temp = head;
        Node<T>* myprev = nullptr;
        int flag = 0;
        while(temp != nullptr){
            if(temp->value == toBeDeleted){
                flag = 1;
                if(temp == head){
                    deleteAtStart();
                    return;
                }
                else if(temp == tail){
                    deleteAtEnd();
                    return;
                }
                else{
                    myprev->next = temp->next;
                    delete temp;
                    return;
                }
            }
            myprev = temp;
            temp = temp->next;
        }
        if(flag == 0){
            cout<<"Value not found in the list\n";
        }
    }
}
template <class T>
void SLL2<T> :: deleteAllOccurances(T value){
    if(isEmpty()){
        cout<<"List is empty\n";
    }
    else{
        Node<T>* temp = head;
        Node<T>* myprev = nullptr;
        int flag = 0;
        while(temp != nullptr){
            if(temp->value == value){
                flag = 1;
                if(temp == head){
                    deleteAtStart();
                    temp = head;
                }
                else if(temp == tail){
                    deleteAtEnd();
                    temp = head;
                }
                else{
                    myprev->next = temp->next;
                    delete temp;
                    temp = myprev->next;
                }
            }
            else{
                myprev = temp;
                temp = temp->next;
            }
        }
        if(flag == 0){
            cout<<"Value not found in the list\n";
        }
    }
}
template <class T>
void SLL2<T> :: display() const{
    Node<T>* temp = head;
    if(head == nullptr){
        cout<<"List is empty\n";
    }
    else{
        Node<T>* temp = head;
        while(temp != nullptr){
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}
template <class T>
void SLL2<T> :: deletekthOccurance(T value, int k){
    if(isEmpty()){
        cout<<"List is empty\n";
    }
    else{
        Node<T>* temp = head;
        Node<T>* myprev = nullptr;
        int count = 0;
        int flag = 0;
        while(temp != nullptr){
            if(temp->value == value){
                count++;
                if(count == k){
                    flag = 1;
                    if(temp == head){
                        deleteAtStart();
                        return;
                    }
                    else if(temp == tail){
                        deleteAtEnd();
                        return;
                    }
                    else{
                        myprev->next = temp->next;
                        delete temp;
                        return;
                    }
                }
            }
            myprev = temp;
            temp = temp->next;
        }
        if(flag == 0){
            cout<<"Value not found in the list\n";
        }
    }
}
template <class T>
int SLL2<T> :: countAllLessThanValue(T value){
    if(isEmpty()){
        cout<<"List is empty\n";
        return 0;
    }
    else{
        Node<T>* temp = head;
        int count = 0;
        while(temp != nullptr){
            if(temp->value < value){
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
}