#include <iostream>
#include"CSLL1.h"
#include "CSLL1.cpp"
using namespace std;
int main(){
    CSLL1<int> list;
    list.append(2);
    list.append(1);
    list.append(2);

    list.append(3);
    list.append(4);
    list.append(2);
    list.append(5);
    list.append(2);
    list.append(6);
    list.append(2);
    // list.addAtStart(0);
    // list.addBefore(3, 6);
    // list.addAfter(4,8);
    // list.addBetween(1,2, 7);
    // list.deleteNode(6);
    // list.countAllLessThan(5);
    list.deleteKth(2,5);
    list.display();
    return 0;
}