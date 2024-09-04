#include<iostream>
#include"SinglyLinkedList.h"
#include"SinglyLinkedList.cpp"
using namespace std;
int main() {
    SinglyLinkedList<int> l1;
    SinglyLinkedList<int> l2;
    l1.append(7);
    l1.sortAsc();
    l1.display();
    // l1.display();
    return 0;
}