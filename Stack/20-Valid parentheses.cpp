#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
    // I'll use a stack to store the last opening parentheses, as
    // it is the first to close
    // If it's closing is found just pop the opening from the stack
    // If it isn't just return false
    // At the end the stack must be empty to return true
    stack<char> openings;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            openings.push(s[i]);
        } else {
            if (openings.empty()) {
                // No opening parentheses are in the string
                return false;
            } 
            // To compare the stack's top
            char top = openings.top();

            if (top == '(' && s[i] == ')' ||
                top == '[' && s[i] == ']' ||
                top == '{' && s[i] == '}') {
                    openings.pop();
                }
        }
    }

    return openings.empty();
}

int main () {
    string input = "([)]";

    cout<<isValid(input)<<endl;

    return 0;
}