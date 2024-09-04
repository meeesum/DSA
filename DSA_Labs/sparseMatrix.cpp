#include "sparseMatrix.h"
#include <iostream>
using namespace std;
template <class T>
Node<T> ::Node(int r, int c, T v)
{
    this->row = r;
    this->col = c;
    this->value = v;
    this->next = nullptr;
}
template <class T>
SparseMatrixLinkedList <T> :: SparseMatrixLinkedList(){
    this->head = nullptr;
}
template <class T>
SparseMatrixLinkedList<T>::~SparseMatrixLinkedList()
{
    while (head != nullptr)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void SparseMatrixLinkedList<T>::Insert(int r, int c, T v)
{
    Node<T>* temp = head;
    while (temp != nullptr)
    {
        Node<T> *newNode = new Node<T>(r, c, v);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node<T> *temp = head;
            while (temp != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}
template <class T>
void SparseMatrixLinkedList<T>::display()
{
    Node<T> *temp = head;
    while (temp->next != nullptr)
    {
        cout << "Row : " << temp->row << " Col: " << temp->col << " Value: " << temp->value;
        temp = temp->next;
    }
}
template <class T>
SparseMatrixLinkedList<T> SparseMatrixLinkedList<T>::addSparseMatrices(SparseMatrixLinkedList &list1, SparseMatrixLinkedList &list2)
{
    SparseMatrixLinkedList<T> result;
    Node<T> *head1 = list1.head;
    Node<T> *head2 = list2.head;
    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->row == head2->row && head1->col == head2->col)
        {
            T sumValue = head1->value + head2->value;
            if (sumValue != 0)
            {
                result.Insert(head1->row, head1->col, sumValue);
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->row < head2->row || (head1->row = head2->row && head1->col < head2->col))
        {
            result.Insert(head1->row, head1->col, head1->value);
            head1 = head1->next;
        }
        else
        {
            result.Insert(head2->row, head2->col, head2->value);
            head2 = head2->next;
        }
        while (head1 != nullptr)
        {
            result.Insert(head1->row, head1->col, head1->value);
            head1 = head1->next;
        }
        while (head2 != nullptr)
        {
            result.Insert(head2->row, head2->col, head2->value);
            head2 = head2->next;
        }
        return result;
    }
}
