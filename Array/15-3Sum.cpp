#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    // First the solution vector is declared
    vector<vector<int>> result;

    // Then the input array is sorted in non decreasing order
    sort(begin(nums), end(nums)); 

    // The question can be defined as an equation: x + y + z = 0
    // We first iterate through the array to find x
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) break; // x can only be a negative integer, as positive integer can't
        // be added together to equal 0

        // To avoid duplicates after the first element 
        // we check if the element before our current x is the same, if it is we skip it
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Left and right pointers are defined to find such numbers y and z that
        // added to x equal 0
        int l = i + 1; // The left pointer always start after x, to avoid duplicates
        int r = nums.size() - 1;

        // After x is found, is just a variation of Two Sum II
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];

            if (sum < 0) {
                l++;
            } else if (sum > 0) {
                r--;
            } else {
                result.push_back({nums[i], nums[l], nums[r]});
                // Pointers shifted inward as a suitable triplet has been found
                l++;
                r--;

                // To avoid duplicates just continue shifting the left pointer
                // until the current y is different to the previous element
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
            cout<<n<<" ";
        }
        cout<<"\n";
    }

    return 0;
}