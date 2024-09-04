#include<iostream>
#include"SLL2.cpp"
#include"SLL2.h"
using namespace std;
int main(){
    SLL2<int> list;
    list.append(5);
    list.append(1);
    list.append(5);
    list.append(2);
    list.append(5);
    list.append(3);
    list.append(5);
    list.append(4);
    list.append(5);
    list.addAtStart(0);
    list.addBefore(3,4);
    list.deletekthOccurance(5,3);
    int c = list.countAllLessThanValue(50);
    list.deleteAtEnd();
    list.deleteAtStart();
    list.deleteAllOccurances(5);
    list.display();

    return 0;
}