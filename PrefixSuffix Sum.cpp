#include <iostream>
#include <vector>

using namespace std;
// Without the current index
void prefixIgnore(vector<int> &nums) {
    vector<int> prefix(nums.size());

    // As there are not elements before nums[0]
    prefix[0] = 0;

    for (int i = 1; i < nums.size(); i++)
        prefix[i] = nums[i - 1] + prefix[i - 1];

    for (int n: prefix)
        cout<<n<<endl;
}

void suffixIgnore(vector<int> &nums) {
    vector<int> suffix(nums.size());
    
    // As there are not elements after nums[nums.size() - 1]
    suffix[nums.size() - 1] = 0;

    for (int i = nums.size() - 2; i >= 0; i--)
        suffix[i] = nums[i + 1] + suffix[i + 1];

    for (int n: suffix)
        cout<<n<<endl;
}

// With the current index
void prefix(vector<int> &nums) {
    vector<int> prefix(nums.size());

    // To avoid accessing an index out of bounds, we
    // set the first element of the prefix array to the first
    // element of the input array, because there are not elements before it
    prefix[0] = nums[0];

    // We iterate through the array calculating the sum from nums[0] to nums[i]
    for (int i = 1; i < nums.size(); i++) 
        prefix[i] = nums[i] + prefix[i - 1];

    for (int n: prefix)
        cout<<n<<endl;
}

void suffix(vector<int> &nums) {
    vector<int> suffix(nums.size());

    // To avoid accessing an index out of bounds, the last element
    // of the suffix array is the last element of the input array
    // as there are not elements after it
    suffix[suffix.size() - 1] = nums[nums.size() - 1];

    //We iterate through the array but in reverse order, to obtain the sum
    // from nums[nums.size() - 1] to nums[i];
    for (int i = nums.size() - 2; i >= 0; i--)
        suffix[i] = nums[i] + suffix[i + 1];

    for (int n: suffix) 
        cout<<n<<endl;
}

int main() {

    vector<int> input = {1, 2, 3, 4, 5, 6, 7};
    prefixIgnore(input);
    suffixIgnore(input);

    return 0;
}