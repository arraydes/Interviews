#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    // Start with two pointers, at the edges of the array
    // then check in the middle of both positions, to split the array
    // in a left and right half
    // If nums[middle] < target, the value can be in the right half, so the left
    // pointer is shifted 1 element before the middle
    // If nums[middle] > target, the value can be in the left half, so the right
    // pointer is shifted 1 element before the middle
    // The array is splitted until the element is found or when both pointers are in the same element
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
        int middle = (l + r) / 2;

        if (nums[middle] == target) return middle;

        if (nums[middle] < target) {
            l = middle + 1;
        } else {
            r = middle - 1;
        }
    }

    // If the target is not inside the array
    return -1;
}
int main() {
    vector<int> input = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    int index = search(input, target);

    if (index != -1)
        cout<<"Element found at: "<<index<<endl;
    else
        cout<<"Not found"<<endl;

    return 0;
}