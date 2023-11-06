#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int performOperation(int operand1, int operand2, char op)
{
    switch (op)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 != 0)
            return operand1 / operand2;
        else
        {
            cerr << "Error: Division by zero." << endl;
            exit(1);
        }
    }
    return 0; // Default case (should not happen)
}

int evaluatePostfix(const string &postfix)
{
    stack<int> operandStack;

    for (char c : postfix)
    {
        if (isdigit(c))
        {
            operandStack.push(c - '0'); // Convert char to integer and push to stack
        }
        else if (isOperator(c))
        {
            // Pop the top two operands from the stack
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            // Perform the operation and push the result back to the stack
            int result = performOperation(operand1, operand2, c);
            operandStack.push(result);
        }
    }

    if (!operandStack.empty())
    {
        return operandStack.top();
    }
    else
    {
        cerr << "Error: Invalid postfix expression." << endl;
        exit(1);
    }
}

int main()
{
    string postfixExpression;

    // Input the postfix expression
    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;

    int result = evaluatePostfix(postfixExpression);

    // Output the result
    cout << "Result: " << result << endl;

    return 0;
}
