#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums) {
    // As the solutions asks for result[i] to be the multiplication of all elements
    // before and after nums[i], a prefix/suffix product of each element is needed
    // and then just result[i] is the multiplication of both
    int n = nums.size();

    vector<int> prefix(n);
    vector<int> suffix(n);
    vector<int> result(n);
    // Both prefix and suffix have to start from 1
    prefix[0] = suffix[n - 1] = 1;

    //
    for (int i = 1; i < n; i++) {
        prefix[i] = nums[i - 1] * prefix[i - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = nums[i + 1] * suffix[i + 1];
    }

    for (int i = 0; i < n; i++) {
        result[i] = prefix[i] * suffix[i];
    }

    return result;
}

int main() {

    vector<int> input = {1, 2, 3, 4};
    vector<int> output = productExceptSelf(input); 

    for (int n: output) {
        cout<<n<<endl;
    }

    return 0;
}