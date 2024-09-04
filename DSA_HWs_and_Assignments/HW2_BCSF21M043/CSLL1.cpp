#include<iostream>
#include"CSLL1.h"
using namespace std;
template <class T>
Node<T> :: Node(){
    this->next = NULL;
}
template <class T>
Node<T> :: Node(T value){
    this->value = value;
    this->next = nullptr;
}
template <class T>
CSLL1<T> :: CSLL1(){
    this->head = nullptr;
}
template <class T>
CSLL1<T> :: ~CSLL1(){
    Node<T>* temp = head;
    while(temp != nullptr){
        Node<T>* nextptr = temp->next;
        delete temp;
        temp = nextptr;
    }
    delete head;
}
template <class T>
bool CSLL1<T> :: isEmpty(){
    if(this->head == nullptr){
        return true;
    }
    else{
        return false;
    }
}
template <class T>
Node<T>* CSLL1<T> :: findTail(){
    Node<T>* tail = head;
    if(head == nullptr){
        return nullptr;
    }
    else{
    while(tail->next != head){
        tail = tail->next;
    }
    return tail;
    }
}
template <class T>
void CSLL1<T> :: addAtStart(T value){
    Node<T>* newNode = new Node<T>(value);
    Node<T>* temp = head;
    Node<T>* tail = head;
    if(isEmpty()){
        this->head = newNode;
        head->next = head;
    }
    else{
    while(tail->next != head){
        tail = tail->next;
    }
    newNode->next = head;
    head = newNode;
    tail->next = head;
    }

}
template <class T>
void CSLL1<T> :: append(T value){
    Node<T>* newNode = new Node<T>(value);
    Node<T>* temp = head;
    Node<T>* tail = findTail();
    if(isEmpty()){
        head = newNode;
        head->next = head;
    }
    else{
            tail->next = newNode;
            newNode->next = head;
    }
}
template <class T>
void CSLL1<T> :: addAfter(T value, T valueToBeAdded){
    Node<T>* newNode = new Node<T>(valueToBeAdded);
    Node<T>* temp = head;
    Node<T>* forward = nullptr;
    Node<T>* myprev = findTail();
    int flag  = 0;
    while(temp->next != head && flag == 0){
        if(temp->value == value){
            flag = 1;
            if(temp->next == head){
                temp->next = newNode;
                newNode->next = head;
            }
            else
            {
                forward = temp->next;
                temp->next = newNode;
                newNode->next = forward;
            }
        }
        myprev = temp;
        temp = temp->next;
    }
    if(flag == 0){
        cout<<"Value not found\n"<<endl;
    }
}
template <class T>
void CSLL1<T> :: addBefore(T value, T valueToBeAdded){
    Node<T>* newNode = new Node<T>(valueToBeAdded);
    Node<T>* tail = head;
    Node<T>* temp = head;
    int flag = 0;
    while(tail->next != head){
        tail = tail->next;
    }
    Node<T>* myprev = tail;
    while(temp->next != head && flag == 0){
        if(temp->value == value){
            flag = 1;
            if(temp == head){
                newNode->next = head;
                head = newNode;
                tail->next = head;
            }
            else{
                myprev->next = newNode;
                newNode->next = temp;
            }
        }
        myprev = temp;
        temp = temp->next;
    }
    if(flag == 0){
        cout<<"Value not found\n"<<endl;
        return;
    }
}
template <class T>
void CSLL1<T> :: deleteNode(T valueToBeDeleted){
    Node<T>* temp = head;
    Node<T>* tail = findTail();
    Node<T>* myprev = tail;
    Node<T>* forward = nullptr;

    int flag = 0;
    while(temp->value != valueToBeDeleted || temp->next != head){
        if(temp->value == valueToBeDeleted && temp == head){
            forward = temp->next;
            tail->next = forward;
            delete temp;
            head = forward;
            flag = 1;
            return;
        }
        else if(temp->value == valueToBeDeleted && temp != head){
            myprev->next = temp->next;
            delete temp;
            temp = myprev->next;
            flag = 1;
            return;
        }
        else if(temp->next == head && temp->value != valueToBeDeleted){
            flag = 0;
        }
        myprev = temp;
        temp = temp->next;
    }
    if(flag == 0){
        cout<<"Value not found\n"<<endl;
    }
}
template <class T>
void CSLL1<T> :: deleteFromEnd(){
    Node<T>* temp = head;
    Node<T>* myprev = nullptr;
    Node<T>* tail = findTail();
    if(isEmpty()){
        cout<<"List is Empty! Cannot Delete\n";
    }
    else if(temp->next == head){
        delete temp;
        head = nullptr;
        cout<<"Head of the List Deleted!\n";
    }
    else{
        while(temp->next != head){
            myprev = temp;
            temp = temp->next;
        }
        myprev->next = head;
        delete temp;
        temp = nullptr;
    }
}
template <class T>
void CSLL1<T> :: deleteFromStart(){
    Node<T>* temp = head;
    Node<T>* tail = findTail();
    if(isEmpty()){
        cout<<"List is Empty! Cannot Delete\n";
        return;
    }
    else if(temp->next == head){
        delete temp;
        head = nullptr;
        return;
    }
    else{
        tail->next = temp->next;
        head = temp->next;
        delete temp;
        return;
    }
}
template <class T>
void CSLL1<T> :: countAllLessThan(T value){
    int flag = 0;
    Node<T>* temp = head;
    int count = 0;
    if(isEmpty()){
        cout<<"The list is empty\n";
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
        if(temp->value < value){
            flag = 1;
            count++;
        }
        if(flag == 0){
            cout<<"No value is less than "<<value<<endl;
        }
        else{
            cout<<"The number of values less than "<<value<<" are: "<<count<<endl;
        }
    }
}
template <class T>
void CSLL1<T> :: deleteKth(T value,int k){
    Node<T>* temp = head;
    Node<T>* myprev = findTail();

    int count = 0;
    int flag = 0;
    if(isEmpty()){
        cout<<"The list is empty\n";
        return;
    }
    else{
        while(temp->next != head && flag == 0){
            if(temp->value == value){
                count++;
                if(count == k && temp == head){
                    flag = 1;
                    myprev->next = temp->next;
                    delete temp;
                    head = myprev->next;
                    temp = head;
                }
                else if(count == k && temp != head){
                    flag = 1;
                    myprev->next = temp->next;
                    delete temp;
                    temp = myprev->next;
                }
            }
            myprev = temp;
            temp = temp->next;
        }
        if(temp->value == value){
            count++;
            if(count == k){
                flag = 1;
                myprev->next = temp->next;
                delete temp;
            }
        }
    }
    if(flag == 0){
        cout<<"Value not found\n";
        return;
    }
}
template <class T>
void CSLL1<T> :: display(){
    Node<T>* temp = head;
    while(temp->next != head){
        cout<<temp->value << "->";
        temp = temp->next;
    }
    cout<<temp->value<<endl;
}