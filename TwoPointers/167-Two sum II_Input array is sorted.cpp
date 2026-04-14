#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    // To pointers to iterate through the array from the left and from the right
    // and check, if numbers[l] + numbers[r] > target, shift r 1 element to the left
    // if numbers[l] + numbers[r] < target, shift l 1 element to the right 
    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {
        if (nums[l] + nums[r] == target) {
            return {++l, ++r};
        } else if (nums[l] + nums[r] > target) {
            r--;
        } else {
            l++;
        }
    }

    return {++l, ++r};
}

int main() {

    vector<int> input1 = {2, 7, 11, 15};
    vector<int> output1 = twoSum(input1, 9);

    for (int n: output1) {
        cout<<n<<endl;
    }
    
    return 0;
}