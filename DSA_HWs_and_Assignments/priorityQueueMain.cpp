#include<iostream>
#include "priorityQueue.h"
#include "priorityQueue.cpp"

using namespace std;
int main(){
    /*I have implemented a printer machine which is open for students and teachers to complete their printing jobs
     students have same priority and teachers and higher priority in heirarchy principal,
      vice principal and other teaching staff.. initially I have added a principal with priority. Initially
      I have added three persons in the Queue Principal with prioriy 1, a techer with prioriy 2 and a 
      student with priority 3.. the priorites are in increasing order... lower with higher priority*/
    PQueue<int> pq; 
    pq.enQueue(10, 2); 
    pq.enQueue(5, 1);  
    pq.enQueue(20, 3); 

    cout << "Initial Queue: ";
    pq.display();
    cout << "\n";

    pq.deQueue();
    cout << "Queue after Dequeue: ";
    pq.display();
    cout << "\n";

    return 0;
}