#include <iostream>
#include "stackUsingDLL.h"
#include <string.h>
using namespace std;
template <class T>
Node<T>::Node()
{
    this->next = nullptr;
    this->prev = nullptr;
}
template <class T>
Node<T>::Node(T value)
{
    this->next = nullptr;
    this->prev = nullptr;
    this->value = value;
}
template <class T>
Stack<T>::Stack()
{
    head = nullptr;
    top = nullptr;
}
template <class T>
Stack<T>::~Stack()
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}
template <class T>
bool Stack<T>::isEmpty()
{
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
T Stack<T>::topOfStack()
{
    return top->value;
}

template <class T>
void Stack<T>::push(T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (isEmpty())
    {
        head = newNode;
        head->prev = nullptr;
        head->next = nullptr;
        top = newNode;
        top->next = nullptr;
    }
    else
    {
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        top->next = nullptr;
    }
}
template <class T>
void Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "The stack is empty\n";
        return;
    }
    else
    {
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            top = nullptr;
            return;
        }
        else
        {
            Node<T> *temp = top;
            top = top->prev;
            delete temp;
            if (top != nullptr)
            {
                top->next = nullptr;
                return;
            }
        }
    }
}
template <class T>
void Stack<T>::display() const
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->value << "->";
        temp = temp->next;
    }
}
template <class T>
bool Stack<T>::isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
int Stack<T>::prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
template <class T>
string Stack<T>::intoPost(string infix)
{
    string postfix = "";
    int len = infix.length();
    int i = 0;
    while (i < len && top != nullptr)
    {
        if (infix[i] == '(')
        {
            push(infix[i]);
            i++;
        }
        else if (isOperator(infix[i]) && prec(infix[i]) < prec(top->value))
        {
            char ch = infix[i];
            while (prec(infix[i]) < prec(top->value) && top != nullptr)
            {
                postfix.append(1, top->value);
                pop();
            }
            push(ch);
            i++;
        }
        else if (infix[i] == ')')
        {
            while (top != nullptr && top->value != '(')
            {
                postfix.append(1, top->value);
                pop();
            }
            pop();
            i++;
        }
        else if (!isOperator(infix[i]) && infix[i] != '(' && infix[i] != ')')
        {
            postfix.append(1, infix[i]);
            i++;
        }
        else if (isOperator(infix[i]) && prec(infix[i]) > prec(top->value))
        {
            push(infix[i]);
            i++;
        }
    }
    return postfix;
}
template <class T>
bool Stack<T>::paranthesisEvaluation(string s)
{
    int len = s.length();
    int i = 0;
    if (s[0] == ')')
    {
        return false;
    }
    while (i < len)
    {
        if (s[i] == '(')
        {
            push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (isEmpty())
            {
                return false;
            }
            else
            {
                pop(); 
            }
        }
        i++;
    
    }
    if (isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
void Stack<T>::visitNew(T value, Stack<T> forward, Stack<T> back)
{
    this->push(value);
    back.push(this->topOfStack());
    this->push(value);
    cout<<this->topOfStack()<<endl;
}
template <class T>
void Stack<T>::navBack(Stack<T> forward, Stack<T> back)
{
    if(back.top == nullptr){
        cout<<"There are no pages to navigate back\n";
    }
    else{
    forward.push(this->topOfStack());
    cout<<back.topOfStack()<<endl;
    this->push(back.topOfStack());
    back.pop();
    }
}
template <class T>
void Stack<T> :: navForw(Stack<T> forward, Stack<T> back){
    if(forward.top == nullptr){
        cout<<"There is no page to forward\n";
    }
    else{
    back.push(this->topOfStack());
    cout<<forward.topOfStack()<<endl;
    this->push(forward.topOfStack());
    forward.pop();
    }
}
template <class T>
void Stack<T> :: typing(T value, Stack<T> undo, Stack<T> redo){
    undo.push(value);
}
template <class T>
void Stack<T> :: undoAction(Stack<T> undo, Stack<T> redo){
    if(undo.top == nullptr){
        cout<<"There is no previous action to Undo\n";
    }
    else{
    redo.push(undo.topOfStack());
    cout<<undo.topOfStack<<endl;
    undo.pop();
    }
}
template <class T>
void Stack<T> :: redoAction(Stack<T> undo, Stack<T> redo){
    if(redo.top == nullptr){
        cout<<"There is no action available to redo\n";
    }
    else{
    undo.push(redo.topOfStack());
    cout<<redo.topOfStack()<<endl;
    redo.pop();
    }
}