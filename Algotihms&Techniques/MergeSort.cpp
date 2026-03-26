#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &leftArray, vector<int> &rightArray, vector<int> &arr) {
    int i, l, r;
    i = l = r = 0;

    while (l < leftArray.size() && r < rightArray.size()) {
        if (leftArray[l] < rightArray[r]) {
            arr[i] = leftArray[l];
            l++;
        } else {
            arr[i] = rightArray[r];
            r++;
        }
        i++;
    }

    // In case there are still elements in one of the 2 branches
    while (l < leftArray.size()) {
        arr[i] = leftArray[l];
        i++; l++;
    }

    while (r < rightArray.size()) {
        arr[i] = rightArray[r];
        i++; r++;
    }
}

void mergeSort(vector<int> &arr) {

    // Base case to stop the recursion
    if (arr.size() <= 1) {
        return;
    }

    // Elements can be copied over using iterators
    vector<int> leftArray(arr.begin(), arr.begin() + arr.size()/2); 
    vector<int> rightArray(arr.begin() + arr.size()/2, arr.end());

    // Call the function until each subarray is of size 1
    mergeSort(leftArray);
    mergeSort(rightArray);

    // Call merge to copy the ordered elements from both branches to a single array
    merge(leftArray, rightArray, arr);
}

int main() {
    vector<int> input = {4, 2, 8, 5, 1, 3};
    
    mergeSort(input);

    for (int n: input) {
        cout<<n<<endl;
    }
    return 0;
}