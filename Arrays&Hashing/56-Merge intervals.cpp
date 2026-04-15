#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merged(vector<vector<int>> &intervals) {
    // Sort the input array
    // Declare an output array to store the merged intervals and enter the first one to compare
    // If the end of the last interval in the merged array lies after the end of the current interval (there is overlap)
    // so just set the end of the last to be the max between the end of the last and the end of the current one
    // If the last ends before the current starts, there's no overlap, so just add it to the list
    sort(begin(intervals), end(intervals));
    vector<vector<int>> mergedIntervals;

    for (vector<int> interval: intervals) {
        if (mergedIntervals.empty() || mergedIntervals.back()[1] < interval[0]) {
            mergedIntervals.push_back(interval);
        } else {
            mergedIntervals.back()[1] = max(mergedIntervals.back()[1], interval[1]);
        }
    }

    return mergedIntervals;
}

int main() {

    vector<vector<int>> input = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> output = merged(input);

    for (vector<int> interval: output) {
        for (int n: interval) {
            cout<<n<<" ";
        }
        cout<<" ,";
    }

    return 0;
}