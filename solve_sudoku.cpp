#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*
    Write a program to solve a Sudoku puzzle by filling the empty cells.
    Empty cells are indicated by the character '.'.
    You may assume that there will be only one unique solution.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board, int x, int y) {
        char c = board[x][y];
        for (int i=0; i<9; ++i)
        {
            if (y != i && board[x][i] == c)
            {
                return false;
            }
            if (x != i && board[i][y] == c)
            {
                return false;
            }
        }
        int xx = x / 3 * 3;
        int yy = y / 3 * 3;
        for (int i=xx; i<xx+3; ++i)
        {
            for (int j=yy; j<yy+3; ++j)
            {
                if (x != i && y != j && board[i][j] == c)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool find_solution(vector<vector<char> > &board, int row, int col) {        
        // find an empty position
        while(row < board.size() && board[row][col] != '.') {
            if(++col == board[0].size()) {
                col = 0;
                row++;
            }
        }

        // if all the cells filled, there is a solution
        if(row == board.size()) return true;

        int next_row, next_col;
        if(col==board[0].size()-1) {
           next_row = row+1;
           next_col = 0;
        }
        else {
           next_row = row;
           next_col = col+1;
        }

        // find solution recursively
        for(int i = 1; i < 10; i++) {
            board[row][col] = i+'0';
            if(isValidSudoku(board, row, col) 
                    && find_solution(board, next_row, next_col))
                return true;
        }

        // back to orginal state
        board[row][col] = '.';

        return false; 
    }

    void solveSudoku(vector<vector<char> > &board) {
        if(board.empty() || board[0].empty()) return; 
        find_solution(board, 0, 0);        
        return;
    }
};

int main() {
    Solution slt;
    vector<vector<char> > board;
    vector<char> row;

    //board.resize(9);

    // row 1
    row.resize(9);
    fill(row.begin(), row.end(), '.');
    row[0]='5'; row[1]='3';row[4]='7';
    board.push_back(row);

    // row 2
    row.resize(9);
    fill(row.begin(), row.end(), '.');
    row[0]='6'; row[3]='1'; row[4]='9'; row[5]='5';
    board.push_back(row);

    // row 3
    row.resize(9);
    fill(row.begin(), row.end(), '.');
    row[1]='9'; row[2]='8'; row[7]='6'; 
    board.push_back(row);

    // row 4
    row.resize(9);
    fill(row.begin(), row.end(), '.');
    row[0]='8'; row[4]='6'; row[8]='3'; 
    board.push_back(row);

    // row 5
    row.resize(9);
    fill(row.begin(), row.end(), '.');
    row[0]='4'; row[3]='8'; row[5]='3'; row[8]='1'; 
    board.push_back(row);

    // row 6
    row.resize(9);
    fill(row.begin(), row.end(), '.');
    row[0]='7'; row[4]='2'; row[8]='6'; 
    board.push_back(row);

    // row 7
    row.resize(9);
    fill(row.begin(), row.end(), '.');
    row[1]='6'; row[6]='2'; row[7]='8'; 
    board.push_back(row);

    // row 8
    row.resize(9);
    fill(row.begin(), row.end(), '.');
    row[3]='4'; row[4]='1'; row[5]='9';  row[8]='5';
    board.push_back(row);

    // row 9
    row.resize(9);
    fill(row.begin(), row.end(), '.');
    row[4]='8'; row[7]='7'; row[8]='9';
    board.push_back(row);

    slt.solveSudoku(board);
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board.size(); j++) {
            if(slt.isValidSudoku(board, i, j) == false) {
                cout << "FALSE!!" << endl;
                return 0;
            }
        }
    }
     
    cout << "SUCCESS!!" << endl;
    cout << endl;
     
    return 0;
}



