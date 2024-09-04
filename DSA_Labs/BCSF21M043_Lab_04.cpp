#include <iostream>
#include "singlylinkedlist.h"
#include "singlylinkedlist.cpp"
using namespace std;
// template <class T>
// struct visitedNodes
// {
//     Node<T> *addr;
//     int index;
// };
class Employee
{
public:
    string name;
    float sal;
    int age;
    Employee()
    {
        name = "";
        sal = 0.0;
        age = 0;
    }
    Employee(string nm, float salary, int ag)
    {
        this->name = nm;
        this->sal = salary;
        this->age = ag;
    }
};
int bubbleSort(int arr[], int len);
int maxDiff(int arr[], int len);
void distinctElements(int arr[], int high, int low, int len);
void sortEmployees(Employee arr[], int len);
template <class T>
void checkCycle(SinglyLinkedList<T> list);
int main()
{
    int arr[7] = {-1,-6,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, len);
    int d = maxDiff(arr, len);
    cout<<"The maximum difference is: " << d;
    // int arr2[4] = {10, 12, 11, 15};
    // int len = sizeof(arr2) / sizeof(arr2[0]);
    // distinctElements(arr2, 15, 10, len);

    // Employee e1("Zain", 1500.0, 21);
    // Employee e2("Meesum", 2000.0, 20);
    // Employee e3("Aftab", 1500.0, 24);
    // Employee arr3[3] = {e1, e2, e3};
    // int len = sizeof(arr3) / sizeof(arr3[0]);

    // sortEmployees(arr3, len);
    // for (int i = 0; i < len; i++)
    // {
    //     cout << arr3[i].name << " " << arr3[i].age << " " << " " << arr3[i].sal << " ";
    // }
    return 0;
}
int bubbleSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
int maxDiff(int arr[], int len)
{
    int slow = 0;
    int fast = 1;
    int maxD = 0;
    int diff = 0;
    for (int i = 0; i < len - 1; i++)
    {
        diff = arr[fast] - arr[slow];
        if (diff > maxD)
        {
            maxD = diff;
        }
        slow++;
        fast++;
    }
    return maxD;
}
void distinctElements(int arr[], int high, int low, int len)
{
    int temp = low;
    bool flag = false;
    int *arr2 = new int[len];
    int index = 0;
    for (int i = 0; i <= len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            flag = false;
            if (temp == arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag = false && arr[i] >= low && arr[i] <= high)
        {
            arr2[index] = arr[i];
            index++;
        }

        temp++;
    }
    for (int i = 0; i < index; i++)
    {
        cout << arr2[i] << " ";
    }
}
void sortEmployees(Employee arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (arr[i].sal > arr[j].sal)
            {
                Employee temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else if (arr[i].sal == arr[j].sal)
            {
                if (arr[i].age < arr[j].age)
                {
                    Employee temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}
// template <class T>
// void checkCycle(SinglyLinkedList<T> list)
// {
//     Node<T>* temp = head;
//     Node<T>* temp1 = head;

    
//     visitedNodes* arr = new visitedNodes [len];
//     int flag = false;
//     int flag2 = false;
//     int i = 0;
//     while(flag != true){
//         visitedNodes[i].addr = temp1;
//         visitedNodes[i].index = i;

//         while(flag2 != true){
//             if(temp == temp1){
//                 flag2 = false;
//                 return false;
//             }
//             temp = temp->next;
//         }
//         i++;
//         temp1 = temp1->next;
//     }
// }