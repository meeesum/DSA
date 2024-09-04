#pragma once
template <class T>
class Node
{
public:
    Node<T>* next;
    Node<T>* prev;
    T value;
    Node();
    Node(T value);
};
template <class T>
class Stack
{
private:
    Node<T> *head;
    Node<T> *top;

public:
    Stack();
    ~Stack();
    bool isEmpty();
    T topOfStack();
    void push(T value);
    void pop();
    void display() const;
    bool isOperator(char c);
    int prec(char value);
    std :: string intoPost(std:: string infix);
    bool paranthesisEvaluation(std:: string s);
    void visitNew(T value, Stack<T> forward, Stack<T> back);
    void navBack(Stack<T> forward, Stack<T> back);
    void navForw(Stack<T> forward, Stack<T> back);
    void typing(T value,Stack<T> undo, Stack<T> redo);
    void undoAction(Stack<T> undo, Stack<T> redo);
    void redoAction(Stack<T> undo, Stack<T> redo);
};