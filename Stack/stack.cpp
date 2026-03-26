#include <iostream>
#include <stack>

using namespace std;

// To get the value to compare of each parentheses
int parenthesesValue(char c) {
    switch (c) {
        case '(':
        case ')':
            return 1;
        case '[':
        case ']':
            return 2;
        case '{':
        case '}':
            return 3;
    }

    return 0;
}

void isValid(string s) {
    stack<char> openings;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' | s[i] == '[' | s[i] == '{') {
            openings.push(s[i]);
        }
    }

    char c = openings.top();
    
    while (!openings.empty()) {
        cout<<openings.top()<<endl;

        openings.pop();
    }
}

int main() {
    string s;
    cin>>s;

    isValid(s);

    return 0;
}