#include<iostream>
#include<stack>
using namespace std;
// c) build and print expression tree
class Node {
    public:
    char value;
    Node* left, *right;
};

Node* newNode(int v) {
    Node* temp = new Node;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};

void printInorder(Node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->value << " ";
    printInorder(node->right);
}

Node* buildTree(string postfix) {
    stack<Node*> st;
    Node *t, *t1, *t2;

    for (int i = 0; i < postfix.length(); i++) {
        if (!isOperator(postfix[i])) {
            t = newNode(postfix[i]);
            st.push(t);
        } else {
            t = newNode(postfix[i]);
            t1 = st.top(); // Pop operands
            st.pop();
            t2 = st.top();
            st.pop();

            t->right = t1;
            t->left = t2;

            st.push(t);
        }
    }

    t = st.top();
    st.pop();

    return t;
}
bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}