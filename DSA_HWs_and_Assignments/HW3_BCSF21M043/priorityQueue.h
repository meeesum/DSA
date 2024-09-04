#pragma once
template <class T>
class Node{
    public:
    T data;
    int priority;
    Node<T>* next;
    Node<T>* prev;
    Node();
    Node(T data, int priority);
};
template <class T>
class PQueue{
    private:
    Node<T>* front;
    Node<T>* rear;
    public:
    PQueue();
    ~PQueue();
    void enQueue(T data, int priority);
    void deQueue();
    void display() const;
    bool isEmpty();
    void addTask(const T& item);
    void addJob(const T &job);
    void processJobs();
};