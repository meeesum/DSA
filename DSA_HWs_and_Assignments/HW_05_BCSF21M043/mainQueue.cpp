#include <iostream>
#include "queue.h"
#include "queue.cpp"
using namespace std;
int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<q.peek()<<endl;
    cout<<q.size()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.isFull()<<endl;
    

    return 0;
}