#include<iostream>
#include"singlylinkedlist.h"
#include"singlylinkedlist.cpp"
using namespace std;
int main(){
    SinglyLinkedList<int> l1;
    l1.bookSeat(2);
    l1.bookSeat(1);
    l1.bookSeat(10);
    l1.bookSeat(5);
    l1.bookSeat(2);
    l1.bookSeat(3);
    l1.bookSeat(15);
    l1.display();
    return 0;
}