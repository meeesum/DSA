#include <iostream>
#include "stack.h"
#include "stack.cpp"
using namespace std;
int main(){
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.pop();
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.isFull()<<endl;
    
    return 0;
}