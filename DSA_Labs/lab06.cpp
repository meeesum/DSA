#include <iostream>

struct Node {
    int row;
    int col;
    int value;
    Node* next;

    Node(int r, int c, int v) {
        row = r;
        col = c;
        value = v;
        next = nullptr;
    }
};

class SparseMatrixLinkedList {
private:
    Node* head;

public:
    SparseMatrixLinkedList() : head(nullptr) {}

    void insert(int row, int col, int value) {
        Node* newNode = new Node(row, col, value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            std::cout << "Row: " << temp->row << ", Column: " << temp->col << ", Value: " << temp->value << std::endl;
            temp = temp->next;
        }
    }

    Node* getHead() const {
        return head;
    }

    ~SparseMatrixLinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

SparseMatrixLinkedList addSparseMatrices(const SparseMatrixLinkedList& mat1, const SparseMatrixLinkedList& mat2) {
    SparseMatrixLinkedList result;
    Node* head1 = mat1.getHead();
    Node* head2 = mat2.getHead();

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->row == head2->row && head1->col == head2->col) {
            int sumValue = head1->value + head2->value;
            if (sumValue != 0) {
                result.insert(head1->row, head1->col, sumValue);
            }
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->row < head2->row || (head1->row == head2->row && head1->col < head2->col)) {
            result.insert(head1->row, head1->col, head1->value);
            head1 = head1->next;
        } else {
            result.insert(head2->row, head2->col, head2->value);
            head2 = head2->next;
        }
    }

    while (head1 != nullptr) {
        result.insert(head1->row, head1->col, head1->value);
        head1 = head1->next;
    }

    while (head2 != nullptr) {
        result.insert(head2->row, head2->col, head2->value);
        head2 = head2->next;
    }

    return result;
}

int main() {
    SparseMatrixLinkedList mat1;
    mat1.insert(0, 1, 5);
    mat1.insert(1, 2, 10);
    mat1.insert(2, 0, 15);

    SparseMatrixLinkedList mat2;
    mat2.insert(0, 1, 3);
    mat2.insert(1, 2, 7);
    mat2.insert(2, 1, 8);

    SparseMatrixLinkedList result = addSparseMatrices(mat1, mat2);

    std::cout << "Resultant Sparse Matrix Representation:" << std::endl;
    result.display();

    return 0;
}