#include <iostream>
#include "Stack.cpp"
#include "Stack.h"
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // Default precedence for non-operators
}

string infixToPostfix(const string& infix) {
    Stack<char> operators;
    string postfix;
    
    for (char c : infix) {
        if (isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.isEmpty() && operators.stackTop() != '(') {
                postfix += operators.stackTop();
                operators.pop();
            }
            operators.pop(); // Remove the '('
        } else if (isOperator(c)) {
            while (!operators.isEmpty() && operators.stackTop() != '(' &&
                   precedence(c) <= precedence(operators.stackTop())) {
                postfix += operators.stackTop();
                operators.pop();
            }
            operators.push(c);
        }
    }
    
    while (!operators.isEmpty()) {
        postfix += operators.stackTop();
        operators.pop();
    }
    
    return postfix;
}

double evaluatePostfix(const string& postfix) {
    Stack<double> operands;
    
    for (char c : postfix) {
        if (isdigit(c)) {
            operands.push(static_cast<double>(c - '0'));
        } else if (isOperator(c)) {
            double operand2 = operands.stackTop();
            operands.pop();
            double operand1 = operands.stackTop();
            operands.pop();
            
            switch (c) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
            }
        }
    }
    
    return operands.stackTop();
}

int main() {
    string infix_expression = "(5 + 3) * 2 / 4";
    string postfix_expression = infixToPostfix(infix_expression);
    double result = evaluatePostfix(postfix_expression);
    
    cout << "Infix to Postfix Conversion:" << endl;
    cout << "Input: " << infix_expression << endl;
    cout << "Postfix Output: " << postfix_expression << endl;
    cout << "\nPostfix Evaluation:" << endl;
    cout << postfix_expression << " evaluates to " << result << endl;
    
    return 0;
}
