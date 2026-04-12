#include <iostream>
#include <vector>

using namespace std;

// This solution is O(3n) in space complexity, there is a way to do it in constant space
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

vector<int> productExceptSelfConstant(vector<int> &nums) {
    // Instead of precomputing the prefix/suffix product in their
    // own separate arrays, it can be calculated on the spot
    // with 2 variables storing the prefix/suffix for each
    // nums[i]
    int n = nums.size();
    vector<int> result(n, 1);

    // Start from 1, as there are no elements before/after 
    // the first and last element of the array
    int prefix, suffix = 1; 

    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    // Instead of assiging the value of suffix to result[i]
    // it is multiplied with what is already there
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}

int main() {

    vector<int> input = {1, 2, 3, 4};
    vector<int> output = productExceptSelfConstant(input); 

    for (int n: output) {
        cout<<n<<endl;
    }

    return 0;
}