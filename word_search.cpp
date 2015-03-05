#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell,
where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.

For example,
    Given board =
        [
          ["ABCE"],
          ["SFCS"],
          ["ADEE"]
        ]

    word = "ABCCED", -> returns true,
    word = "SEE", -> returns true,
    word = "ABCB", -> returns false.
*/

class Solution {
public:
    bool dfs(vector<vector<char> > &board,
              string& word, 
              int row,
              int col,
              int pos) {
        if(pos == word.size())
            return true;

        if(row < 0 
             || col < 0
             || row >= board.size() 
             || col >= board[row].size()) 
            return false;

        char tmp;
        if(word[pos] == board[row][col]) {  
            tmp = word[pos];
            board[row][col] = 0;
            pos++;
        }
        else 
            return false;
        
        bool ret = false;
        // up
        if( dfs(board, word, row-1, col, pos)) {
            ret = true;
        }
        // down
        else if(dfs(board, word, row+1, col, pos)) {
            ret = true;
        }
        // left
        else if(dfs(board, word, row, col-1, pos)) {
           ret = true;
        }
        // right
        else if(dfs(board, word, row, col+1, pos)) {
           ret = true;
        }

        board[row][col] = tmp;
        return ret;
    }

    bool exist(vector<vector<char> > &board, string word) {
        for(int i = 0; i < board.size(); i ++) 
           for(int j = 0; j < board[i].size(); j++) {
               if(dfs(board, word, i, j, 0)) 
                   return true;
           }
    }
};

int main() {
    Solution s;
    vector<vector<char> > board;
    vector<char> row(4);
    row[0] = 'A'; row[1] = 'B'; row[2] = 'C'; row[3] = 'E';
    board.push_back(row);
    row[0] = 'S'; row[1] = 'F'; row[2] = 'C'; row[3] = 'S';
    board.push_back(row);
    row[0] = 'A'; row[1] = 'D'; row[2] = 'E'; row[3] = 'E';
    board.push_back(row);

    string word;
    word = "ABCCED";
    cout << word << ": " << s.exist(board, word) << endl;
    word = "SEE";
    cout << word << ": " << s.exist(board, word) << endl;
    word = "ABCB";
    cout << word << ": " << s.exist(board, word) << endl;

    return 0;
}


