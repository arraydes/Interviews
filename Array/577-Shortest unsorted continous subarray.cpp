#include <iostream>
#include <vector>

using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    // Iterate 2 times through the array, from left to right and right to left to find
        // the boundries of the unsorted subarray, to find if the min seen/max seen respectivelly
        // aren't in their correct position
        int n = nums.size();
        int left = -1, right = -1;
        int maxSeen = nums[0];
        int minSeen = nums[n - 1];

        // Iterate through right to left to find the element bigger than  minSeen
        // which tells me the beginning of the unsorted subarray, so left is updated to i
        for (int i = n - 2; i >= 0; i--) {
            minSeen = min(minSeen, nums[i]);

            if (nums[i] > minSeen) {
                left = i;
            }
        }

        // If the beginning of the unsorted subarray is not found, the array is sorted, so we return 0
        if (left == -1) {
            return 0;
        }

        // Iterate through left to right to find the element smaller than maxSeen
        // which tells me the end of the unsorted subarray, so right is updated to i
        for (int i = 1; i < n; i++) {
            maxSeen = max(maxSeen, nums[i]);

        if (nums[i] < maxSeen) {
            right = i;
        }
    }

    // Finally the length of the unsorted subarray is returned
    return right - left + 1;
}

int main() {

    vector<int> input = {2,6,4,8,10,9,15};

    cout<<findUnsortedSubarray(input)<<endl;

    return 0;
}