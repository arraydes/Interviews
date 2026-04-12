#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    // First we declare the result array
    vector<vector<int>> result;

    // Then the input array is sorted in non decreasing order
    sort(begin(nums), end(nums));

    // The sum can be defined as x + y + z = 0
    // So we iterate through the array to find x, x can only be
    // a negative integer, as positive integers can't be added together to 
    // equal 0
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) break;
        // To avoid duplicates, we skip the current x until it is not
        // equal to the element before it
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Left and right pointers are needed to find y and z, such that
        // they add to 0 when added to x
        int l = i + 1; // To avoid duplicates the left pointer always start after the current x
        int r = nums.size() - 1;

        // The rest of the problem is a variation of two sum II
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];

            if (sum < 0) {
                l++;
            } else if (sum > 0) {
                r--;
            } else {
                result.push_back({nums[i], nums[l], nums[r]});
                // When a solution is found, pointers are shifted inward
                l++;
                r--;

                // To again avoid duplicates, the left pointer is shifted to the right
                // until the current y is different to the element before it
                while (l < r && nums[l] == nums[l - 1]) {
                    l++;
                }
            }
        }
    }

    return result;
}

int main() {
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> output = threeSum(input);

    for (vector<int> v: output) {
        for (int n: v) {
            cout<<n<<", ";
        }

        cout<<"\n";
    }
    return 0;
}