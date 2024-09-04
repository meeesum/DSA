#include<iostream>
#include "circularQueue.h"
#include "circularQueue.cpp"
using namespace std;
int main(){
   Queue<int> q;

    q.enQueue(5);
    q.enQueue(3);
    q.enQueue(8);

    cout << "Initial Queue: ";
    q.display();
    cout<<"\n";

    q.processes();

    return 0;
}