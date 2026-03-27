#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums) {    
    // I declare it here, because I'll use it to shift non zero elements
    // within the input vector, this pointer after iterating through the vector
    // once will be at the last non zero element, so after nums[j] there have to be
    // only 0s
    int j = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }

    for (; j < nums.size(); j++) {
        nums[j] = 0;
    }
}

int main() {

    vector<int> input = {0, 1, 0, 3, 12};

    moveZeroes(input);

    for (int n: input) {
        cout<<n<<endl;
    }

    return 0;
}