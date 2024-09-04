#include<iostream>
#include "CDLL2.h"
#include "CDLL2.cpp"
using namespace std;
int main(){
    CDLL2<int> l1;
    l1.append(2);
    l1.append(1);
    l1.append(2);
    l1.append(3);
    l1.append(2);
    l1.append(4);
    l1.append(5);
    l1.append(2);
    l1.deleteKth(2,4);
    l1.display();
    return 0;
}