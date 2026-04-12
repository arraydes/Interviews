#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    // I will iterate through each cell using 2 loops, storing the elements seen
    // so far for each row/column into a hashmap, each 3x3 grid will be stored into
    // a map to check for duplicates inside the entire 3x3 grid
    // the key of each grid is a pair derived from the current cell being looked at, by dividing
    // the i and j indexes by 3
    unordered_map<int, unordered_set<char>> seenRow, seenColumn;
    map<pair<int, int>, unordered_set<char>> grid;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                    
                if (seenRow[i].count(board[i][j]) ||
                    seenColumn[j].count(board[i][j]) ||
                    grid[{i/3, j/3}].count(board[i][j])) {
                        return false;
                    }
                    
                seenRow[i].insert(board[i][j]);
                seenColumn[j].insert(board[i][j]);
                grid[{i/3, j/3}].insert(board[i][j]);
            }
        }
    }

    return true;
}

int main() {

    vector<vector<char>> board =
    {{'1','2','.','.','3','.','.','.','.'},
    {'4','.','.','5','.','.','.','.','.'},
    {'.','9','8','.','.','.','.','.','3'},
    {'5','.','.','.','6','.','.','.','4'},
    {'.','.','.','8','.','3','.','.','5'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','.','.','.','.','.','2','.','.'},
    {'.','.','.','4','1','9','.','.','8'},
    {'.','.','.','.','8','.','.','7','9'}};

    cout<<isValidSudoku(board)<<"\n";

    return 0;    
}