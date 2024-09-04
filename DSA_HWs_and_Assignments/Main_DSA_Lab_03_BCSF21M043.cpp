#include<iostream>
#include<string>
#include"Dll2.h"
#include"Dll2.cpp"
#include"singlylinkedlist.h"
#include"singlylinkedlist.cpp"
#include"stackUsingDLL.h"
#include"stackUsingDLL.cpp"
bool isPallindorme(SinglyLinkedList<int> list);
void atmCashWithdraw(int amount);
void findPairSum(DoublyLinkedList<int>,int x);
bool blockMatching(string s1);
template <class T>
bool isCircular(SinglyLinkedList<T> list);
using namespace std;
int main(){

    /*Task 01*/

    SinglyLinkedList<int> l1;
    l1.append(1);
    l1.append(2);
    l1.append(2);
    l1.append(1);

    isPallindorme(l1);

    /*Task 02*/

    string s1 = "{[()]}";
    string s2 = "{[(])}";

    if(blockMatching(s1)){
        cout<<"The block is Valid\n";
    }
    else{
        cout<<"The block is not Valid\n";
    }
    /*Task 03*/
    DoublyLinkedList<int> l2;
    l2.append(1);
    l2.append(2);
    l2.append(4);
    l2.append(5);
    l2.append(6);
    l2.append(7);
    findPairSum(l2, 3);

    /*Task 04*/

    atmCashWithdraw(7000);
    
    /*Task 05*/

    isCircular(l1);

    return 0;
}
template <class T>
bool isPallindorme(SinglyLinkedList<int> list){
    Node<T>* h = list->head;
    Stack<T> s1;
    int len = list.length();
    int i = 0;
    int flag = 0;
    while( i < len/2){
        s1.push(h->value);
        h = h->next;
        i++;
    }
    if(len%2 != 0){
        i++;
        }
    while(i < len){
        int val = s1.top();
        if(val != h->value){
            flag = 1;
            return false;
        }
        s1.pop();
    i++;
    }
    if(flag == 0){
        return true;
    }
}
void atmCashWithdraw(int amount){
    if(amount < 500){
        return;
    }
    else if(amount <= 1000){
        cout<<" 500 ";
        atmCashWithdraw(amount-500);
    }
    else if(amount > 1000 && amount < 5001){
        cout<<" 1000 ";
        atmCashWithdraw(amount - 1000);
    }
    else if(amount > 5000){
        cout<<" 5000 " ;
        atmCashWithdraw(amount - 5000);
    }
}
template <class T>
bool isCircular(SinglyLinkedList<T> list){
    Node<T>* temp = list->head;
    int len = list.length();
    int i = 0;
    if(list.isEmpty()){
        cout<<"The list is empty\n";
        return;
    }
    else{
    while(i < len){
        temp = temp->next;
        i++;
    }
    if(temp->next == head){
        return true;
    }
    else{
        return false;
    }
    }
}
template <class T>
void findPairSum(DoublyLinkedList<int> , int x){
    Node<T>* start = list.head;
    Node<T>* end = list.tail;

    while (start != end && start->prev != end) {
        int sum = start->value + end->value;

        if (sum == x) {
            cout << "(" << start->value << ", " << end->value << ")\n";
            start = start->next;
            end = end->prev;
        } else if (sum < x) {
            start = start->next;
        } else {
            end = end->prev;
        }
    }
}
bool blockMatching(string s1){
    Stack<char> stack;
    int len = s1.length();

    for (int i = 0; i < len; i++) {
        char c = s1[i];

        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (stack.isEmpty()) {
                return false;
            }

            char topval = stack.topOfStack();
            if ((c == ')' && topval != '(') ||
                (c == '}' && topval != '{') ||
                (c == ']' && topval != '[')) {
                return false;
            }
            stack.pop();
        }
    }

    if(stack.isEmpty()){
        return true;
    }
    else{
        return false;
    }
}
