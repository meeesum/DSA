#include <iostream>
#include "DoublyLinkedList.h"
#include "DoublyLinkedList.cpp"
int main(){
    DoublyLinkedList<int> list1;
    DoublyLinkedList<int> list2;

    list1.append(1);
    list1.append(2);
    list1.append(3);

// Populate list2
    list2.append(4);
    list2.append(5);

// Correctly get the intersection node
    Node<int> intersectionNode = list1.getNode(2); // Get node with value 3 from list1
    list2.getNode(1)->next = intersectionNode; // Make the last node of list2 point to the intersection node

// Correctly call the findIntersectionNode function
    

    return 0;
}