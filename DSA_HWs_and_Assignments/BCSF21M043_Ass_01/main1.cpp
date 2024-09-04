#include<iostream>
#include "Dll1.h"
#include "Dll1.cpp"
using namespace std;
int main(){
    DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    list.append(7);
    list.append(8);
    list.append(9);
    list.append(10);
    list.display();

    return 0;
}