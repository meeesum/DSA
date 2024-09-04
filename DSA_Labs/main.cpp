#include <iostream>
#include "SinglyLinkedList.h"
#include "SinglyLinkedList.cpp"
using namespace std;
int main(){
    SinglyLinkedList<int> l1;
    SinglyLinkedList<int> l2;
    l1.append(1);
    l1.append(2);
    l1.append(3);
    l1.append(4);
    l1.append(5);

    l2.append(6);
    l2.append(7);
    l2.append(8);

    // Create an intersection point
    Node<int>* intersection = new Node<int>(9); // Assuming Node is the node structure used by SinglyLinkedList
    l1.appendNode(intersection); // Assuming appendNode is a method to append an existing node

    // Make l2 intersect l1 at the intersection point
    l2.appendNode(intersection);

    // Optionally, append more nodes to l1 after the intersection if needed
    l1.append(10);
    l1.append(11);

    // Display both lists to verify the intersection
    cout << "List 1: ";
    l1.display(); // Assuming display prints the list
    cout << "List 2: ";
    l2.display();
    



    return 0;
}