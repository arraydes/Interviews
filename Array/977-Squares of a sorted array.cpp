#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);

    // The two pointers start from the edges of the array
    // as the biggest numbers (negative or positive) lie nearest to the edges
    int l = 0;
    int r = n - 1;

    // We iterate through the array from the last index to the first, as bigger squares 
    // lie neearest to the edges
    for (int i = r; i >= 0; i--) {
        // We check if the number with the biggest absolute value is negative (from the left of the array)
        // or positive (from the right of the array)
        if (abs(nums[r]) > abs(nums[l])) {
            result[i] = nums[r] * nums[r];
            r--; // We get closer to the middle of the array each time a square is added to the result array
        } else {
            result[i] = nums[l] * nums[l];
            l++;
        }
    }

    return result;
}

int main() {
    vector<int> input = {-4, -1, 0, 3, 10};
    vector<int> output = sortedSquares(input);

    for (int n: output) {
        cout<<n<<endl;
    }

    return 0;
}