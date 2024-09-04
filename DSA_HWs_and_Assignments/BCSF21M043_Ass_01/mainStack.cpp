#include<iostream>
#include "stackUsingSLL1.h"
#include "stackUsingSLL1.cpp"
int main(){
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    // s.pop();
    s.display();
    return 0;
}