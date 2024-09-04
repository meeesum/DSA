#include<iostream>
#include "queue.h"
#include "queue.cpp"
using namespace std;
int main(){
    Queue<string> q;
    q.enQueue("Student1");
    q.enQueue("Student2");
    q.enQueue("Student3");
    q.enQueue("Student4");
    q.enQueue("Student5");
    return 0;
}