#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    // Iterate through the array from left to right and right to left
    // to get the tallest height that can be most extended to the left and right
    // Also keep the indexes in increasing height order inside a stack, to keep the nearest
    // smallest height for each position
    int n = heights.size();
    
    // Arrays to store the distance to where a smaller bar to the left and right for each position is 
    vector<int> leftBar(n, -1); // If there is none, it is -1
    vector<int> rightBar(n, n); // If there is none, it is the last index
    
    // Stack to store the indexes sorted for increasing height
    stack<int> minLeft, minRight;
    int area = 0;

    for (int i = 0; i < n; i++) {
        while (!minLeft.empty() && heights[minLeft.top()] >= heights[i]) {
            minLeft.pop();
        }

        if (!minLeft.empty()) leftBar[i] = minLeft.top();

        minLeft.push(i);
    }

    for (int i = n - 1; i >= 0; i--) {
        while (!minRight.empty() && heights[minRight.top()] >= heights[i]) {
            minRight.pop();
        }

        if (!minRight.empty()) rightBar[i] = minRight.top();

        minRight.push(i);
    }

    for (int i = 0; i < n; i++) {
        leftBar[i] += 1;
        rightBar[i] -= 1;

        int width = rightBar[i] - leftBar[i] + 1; // +1 as the min width is 1

        area = max(heights[i] * width, area);
    }

    return area;
}

int main() {
    vector<int> input = {2, 1, 5, 6, 2, 3};
    cout<<"Area of largest rectangle: "<<largestRectangleArea(input)<<endl;

    return 0;
}