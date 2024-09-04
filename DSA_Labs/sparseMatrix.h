#pragma once
template <class T>
class Node{
    public:
    int row;
    int col;
    T value;
    Node<T>* next;

    Node(int r, int c, T v);

};
template <class T>
class SparseMatrixLinkedList{
    Node<T>* head;
    public:
    SparseMatrixLinkedList();
    ~SparseMatrixLinkedList();
    void Insert(int r, int  c, T  v);
    void display();
    SparseMatrixLinkedList<T> addSparseMatrices(SparseMatrixLinkedList &list1, SparseMatrixLinkedList &list2);
};