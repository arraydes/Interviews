#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int> &height) {
    // I create a prefix and suffix array to store the max height
    // seen so far for each index
    // The total area of water trapped between 2 bars is now
    // min(height[l], height[r]) - height[i] where i is the current position
    // l and r are the bars immediate to it
    // At the end just iterate through both arrays getting the min heigth immediate
    // to the current position
    int n = height.size();
    
    vector<int> prefix(n);
    vector<int> suffix(n);
    int totalArea = 0;

    // The first and last elements of the prefix/suffix arrays respectivelly
    // are the first and last elements from the original array, as those
    // don't have a bar before it, so the max height so far is the current one
    prefix[0] = height[0]; suffix[n - 1] = height[n - 1]; 

    for (int i = 1; i < n; i++) {
        prefix[i] = max(height[i], prefix[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = max(height[i], suffix[i + 1]);
    }

    for (int i = 0; i < n; i++) {
        totalArea += min(prefix[i], suffix[i]) - height[i];
    }

    return totalArea;
}

int main() {

    vector<int> input = {0, 2, 0, 3, 1, 0, 1, 3, 2, 1};

    cout<<trap(input)<<endl;

    return 0;
}