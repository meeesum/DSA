#include "Dll2.h"

template <class T>
Node<T>::Node(){
    this->prev = nullptr;
    this->next = nullptr;

}

template <class T>
Node<T> :: Node(T value) {
    this->value = value;
    this->prev = nullptr;
    this->next = nullptr;

}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    head = nullptr;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void DoublyLinkedList<T>::append(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}


template <class T>
void DoublyLinkedList<T>::addAtStart(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template <class T>
void DoublyLinkedList<T>::addBetween(T value1, T value2, T value3) {
    Node<T>* current = head;
    while (current != nullptr && !(current->value == value1 && current->next != nullptr && current->next->value == value2)) {
        current = current->next;
    }
    if (current != nullptr && current->next != nullptr) {
        Node<T>* newNode = new Node<T>(value3);
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

template <class T>
void DoublyLinkedList<T>::addAfter(T value) {
    Node<T>* current = head;
    while (current != nullptr && current->value != value) {
        current = current->next;
    }
    if (current != nullptr) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
   
}

template <class T>
void DoublyLinkedList<T>::addBefore(T value) {
    Node<T>* current = head;
    while (current != nullptr && current->next != nullptr && current->next->value != value) {
        current = current->next;
    }
    if (current != nullptr && current->next != nullptr) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

template <class T>
void DoublyLinkedList<T>::deleteAtStart() {
    if (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }
}

template <class T>
void DoublyLinkedList<T>::deleteAtEnd() {
    if (head != nullptr) {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        if (current->prev != nullptr) {
            current->prev->next = nullptr;
        } else {
            head = nullptr;
        }
        delete current;
    }
}

template <class T>
void DoublyLinkedList<T>::deleteFirst(T value) {
    Node<T>* current = head;
    while (current != nullptr && current->value != value) {
        current = current->next;
    }
    if (current != nullptr) {
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        delete current;
    }
}

template <class T>
void DoublyLinkedList<T>::deleteAll(T value) {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* nextNode = current->next;
        if (current->value == value) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            delete current;
        }
        current = nextNode;
    }
}

template <class T>
void DoublyLinkedList<T>::display() const {
    Node<T>* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

template <class T>
void DoublyLinkedList<T>::deletekth(T value, int k) {
    Node<T>* current = head;
    int count = 0;
    while (current != nullptr) {
        if (current->value == value) {
            count++;
            if (count == k) break;
        }
        current = current->next;
    }
    if (current != nullptr) {
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        delete current;
    }
}

template <class T>
bool DoublyLinkedList<T>::isEmpty() {
    return head == nullptr;
}
template <class T>
int DoublyLinkedList<T> :: length(){
    Node<T>* temp = this->head;
    int count = 0;
    while(temp->next != nullptr){
        count++;
    }
    return count;
}