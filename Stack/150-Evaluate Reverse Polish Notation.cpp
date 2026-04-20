#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int evalRPN(vector<string> &tokens) {
    // Use a stack to store tokens that are operands, when an operator is encountered
    // pop the 2 last elements from the stack and perform the specified operation
    // At the end the result of the expression is left in the stack
    stack<int> operands;

    for (string token: tokens) {
        // The order of operators matter in substraction and division, the first element popped from the
        // stack is the "right side operand"
        int a, b;
        if (token == "+") { 
            b = operands.top();
            operands.pop();

            a = operands.top();
            operands.pop();

            operands.push(a + b);
        } else if (token == "-") { 
            b = operands.top();
            operands.pop();

            a = operands.top();
            operands.pop();

            operands.push(a - b);
        } else if (token == "*") { 
            b = operands.top();
            operands.pop();

            a = operands.top();
            operands.pop();

            operands.push(a * b);
        } else if (token == "/") { 
            b = operands.top();
            operands.pop();

            a = operands.top();
            operands.pop();

            operands.push(a / b);
        } else {
            operands.push(stoi(token));
        }
    }

    return operands.top();
}

int main() {
    vector<string> input = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<evalRPN(input)<<endl;

    return 0;
}