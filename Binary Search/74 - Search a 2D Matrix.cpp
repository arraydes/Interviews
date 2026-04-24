#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // As the matrix is also increasingly sorted binary search can be applied in a
    // similar way to the 1D array approach
    // First, apply binary search to find the row there it is most possible for the 
    // value to be inside, comaparing just the first and last element for each row
    // going "up" or "down" the rows if the target:
    // if it is bigger go down a row
    // if it is smaller go up a row
    // When the row is found break from the loop and perform normal binary search in that row
    int rows = matrix.size(), columns = matrix[0].size();
    
    int first = 0, last = rows - 1;

    while (first <= last) {
        int middleRow = (first + last) / 2;

        if (target > matrix[middleRow][columns - 1]) {
            first = middleRow + 1;
        } else if (target < matrix[middleRow][0]) {
            last = middleRow - 1;
        } else {
            break;
        }
    }

    if (!(first <= last)) return false;

    int middleRow = (first + last) / 2;
    int l = 0, r = columns - 1;

    while (l <= r) {
        int middle = (l + r) / 2;
        
        if (matrix[middleRow][middle] == target) return true;

        if (matrix[middleRow][middle] < target) {
            l = middle + 1;
        } else {
            r = middle - 1;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> input = {{1,2,4,8},{10,11,12,13},{14,20,30,40}};
    int target = 10;

    cout<<searchMatrix(input, target)<<endl;
}

