#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;
bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int precedence(char ch){
    if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    return 0;
}
int performOperation(int operand1, int operand2, char op){
    switch (op){
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 != 0)
            return operand1 / operand2;
        else{
            cerr << "Error: Division by zero." << endl;
            exit(1);
        }
    }
    return 0; // Default case (should not happen)
}
string infixToPostfix(const string &infix){
    stack<char> operatorStack;
    ostringstream postfix;
    int i = 0;
    while (i < infix.length()){
        if (isdigit(infix[i])){
            while (i < infix.length() && (isdigit(infix[i]) || infix[i] == '.')){
                postfix << infix[i];
                i++;
            }
            postfix << ' ';
        }else if (isOperator(infix[i])){
            while (!operatorStack.empty() && isOperator(operatorStack.top()) &&
                   (precedence(infix[i]) <= precedence(operatorStack.top()))){
                postfix << operatorStack.top() << ' ';
                operatorStack.pop();
            }
            operatorStack.push(infix[i]);
            i++;
        }else if (infix[i] == '('){
            operatorStack.push(infix[i]);
            i++;
        }else if (infix[i] == ')'){
            while (!operatorStack.empty() && operatorStack.top() != '('){
                postfix << operatorStack.top() << ' ';
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '('){
                operatorStack.pop();
            }else{
                cerr << "Error: Mismatched parentheses." << endl;
                exit(1);
            }
            i++;
        }
        else if (infix[i] == ' '){
            i++;
        }else{
            cerr << "Error: Invalid character in infix expression." << endl;
            exit(1);
        }
    }
    while (!operatorStack.empty()){
        if (operatorStack.top() == '('){
            cerr << "Error: Mismatched parentheses." << endl;
            exit(1);
        }
        postfix << operatorStack.top() << ' ';
        operatorStack.pop();
    }
    return postfix.str();
}
int evaluatePostfix(const string &postfix){
    stack<int> operandStack;
    istringstream iss(postfix);
    string token;
    while (iss >> token){
        if (isdigit(token[0])){
            int operand = stoi(token);
            operandStack.push(operand);
        }else if (isOperator(token[0])){
            if (operandStack.size() < 2){
                cerr << "Error: Invalid postfix expression." << endl;
                exit(1);
            }
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            int result = performOperation(operand1, operand2, token[0]);
            operandStack.push(result);
        }else{
            cerr << "Error: Invalid character in postfix expression." << endl;
            exit(1);
        }
    }
    if (operandStack.size() != 1){
        cerr << "Error: Invalid postfix expression." << endl;
        exit(1);
    }
    return operandStack.top();
}
int main(){
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;
    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;
    return 0;
}
