#include<iostream>
#include"CSLL1.h"
#include"CSLL1.cpp"
int main(){
    CSLL1<int> l1;
    l1.deleteKth(2,1);
    l1.addAfter(1,0);
    l1.addBefore(5,9);
    cout<<"hello";
    return 0;
}