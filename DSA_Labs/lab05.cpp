#include <iostream>
#include "stackUsingDLL.h"
#include "stackUsingDLL.cpp"
#include "Dll2.h"
#include "Dll2.cpp"
using namespace std;
int ways = 0;
int climbingStaircase(int n);
string arrangingLibrary(string books, int start);
void constructTower(int n, int arr[]);
int main()
{
    // int way = climbingStaircase(3);
    // cout<<"There are "<<way <<" to climb these stiars";

    string s = "/u/love\\i\\";
    string r = arrangingLibrary(s, 0);
    cout << r << "\n";

    return 0;
}
int climbingStaircase(int n)
{
    if (n < 1)
    {
        return ways;
    }
    ways++;
    return climbingStaircase(n - 1) + climbingStaircase(n - 2);
}
string arrangingLibrary(string s, int start)
{
    Stack<char> s1;
    int len = sizeof(s1) / sizeof(s[0]);
    string result = "";
    int i = start;
    for (; i < len; i++)
    {
        if (s[i] == '\\')
        {
            while (s1.topOfStack() != '/')
            {
                result += s1.topOfStack();
                s1.pop();
            }
        }
        if (s[i] == '//')
        {
            while (s1.topOfStack() != '\\')
            {
                result += s1.topOfStack();
                s1.pop();
            }
        }
    }
    if (i < len - 1)
    {
        arrangingLibrary(s, i);
    }
    return result;
}
void constructTower(int n, int arr[])
{
    DoublyLinkedList<int> list;
    for (int i = 0; i < n; i++)
    {
        if (list.isEmpty() && list.head->value - arr[i] != 1)
        {
            cout<<"\n";
            list.append(arr[i]);
            i++;
        }
        else
        {
            if(list.head->value - arr[i] == 1){
                list.append(arr[i]);
                cout<<list.head->value;
                cout<<arr[i];
                list.deleteAtStart();
                i++;
            }
            else{
            Node<int>* newNode = new Node(arr[i]);
            Node<int>* front = list->head;
            Node<int>* rear = list->rear;
            while(temp->next != nullptr){
                if(temp->value - arr[i] = 1){
                    cout<<temp->value
;                }
            }
            }
        }
    }
}