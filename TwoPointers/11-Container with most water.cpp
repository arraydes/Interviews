#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    // The formula for the area can be expressed as d(distance between bars) * minHeight
    // So using two pointers, both starting from the edges of the array, I can calculate
    // the area between the two, only moving inward the pointer with the smaller height
    // updating only the area if the current one is bigger
    int l = 0, r = height.size() - 1;
    int area = (r - l) * min(height[l], height[r]);

    while (l < r) {
        if (height[l] < height[r]) {
            l++;
        } else { // If heights are equal, the right pointer is shifted
            r--;
        }

        int currentArea = (r - l) * min(height[l], height[r]);
        area = max(area, currentArea);
    }

    return area;
}

int main() {

    vector<int> input = {1,7,2,5,4,7,3,6};

    cout<<"Max area = "<<maxArea(input)<<"\n";

    return 0;
}