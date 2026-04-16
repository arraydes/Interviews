#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinStack {
public:
    // A list to mantain the elements of the stack and another list
    // to keep the minimum element of each position of the stack
    vector<int> v, minList;

    MinStack() {
        v;
        minList;
    }
    
    void push(int val) {
        // when pushing, the first element of the stack is also the minimum element so far
        // so the value gets inserted in both lists
        if (v.empty()) minList.push_back(val);

        v.push_back(val);
        // Only the smallest value between the given one and the top of the minList is inserted into the minList
        minList.push_back(min(val, minList.back()));
    }
    
    void pop() {
        // When popping the top is removed from both lists
        v.pop_back();
        minList.pop_back();
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return minList.back();
    }
};

int main() {
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout<<minStack->getMin()<<endl; // return -3
    minStack->pop();
    cout<<minStack->top()<<endl;    // return 0
    cout<<minStack->getMin()<<endl; // return -2

    return 0;
}