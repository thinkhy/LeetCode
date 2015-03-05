#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <memory>
#include <limits>
#include <utility>
#include <cstdio>
#include <cstring>
#include <climits>      // for INT_MAX
using namespace std;

#define DE(a) cout << #a << ": " << (a) << endl;
#define EXPECT(a, b) cout << #a << ": result: " << (a) \
                                << "  expect: " << (b) << endl;

/*********************************************************************************************
 *
 * Surrounded regions
 *
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 * 
 * For example,
 *
 *   X X X X
 *   X O O X
 *   X X O X
 *   X O X X
 *
 * After running your function, the board should be:
 * 
 *   X X X X
 *   X X X X
 *   X X X X
 *   X O X X
 *
 *********************************************************************************************/
class Solution {
public:
    vector<pair<int, int> > move_step; 

    void dfs(vector<vector<char> > board, 
             vector<vector<bool> > &visited, vector<pair<int, int> > &cache,
             bool &isSurrounded, int row, int col) {

       visited[row][col] = true;
       cache.push_back(make_pair(row, col));

       for(int i = 0; i < 4; i++) { 
           int next_row = row + move_step[i].first;
           int next_col = col + move_step[i].second;

           if(next_row < 0 || next_row >= board.size() 
                   || next_col < 0 || next_col >= board[0].size()) {
               isSurrounded = false;
           }
           else if(board[next_row][next_col] == 'O' 
                       && visited[next_row][next_col] == false) {
               dfs(board, visited, cache, isSurrounded, next_row, next_col);
           }
       }

       return;
    }

    void solve(vector<vector<char> > &board) {
        if (board.empty())
            return;
                                         
        int row = board.size();        
        int col = board[0].size();        

        vector<vector<bool> > visited(row, vector<bool>(col, false));
        vector<pair<int, int> > cache;
        bool isSurrounded = true;
        cache.reserve(row*col);

        move_step.resize(4);
        move_step[0] = {0,-1};
        move_step[1] = {0,1};
        move_step[2] = {-1,0};
        move_step[3] = {1,0};

        for(int i = 1; i < row-1; i++) {
            for(int j = 1; j < col-1; j++) {
                if(board[i][j] == 'O' && visited[i][j] == false) { 
                    dfs(board, visited, cache, isSurrounded, i, j);
                    if(isSurrounded) {
                        for(int k = 0; k < cache.size(); k++) {
                            board[cache[k].first][cache[k].second] = 'X';
                        }
                    }
                    else  {
                        isSurrounded = true;
                    }
                    cache.clear();
                }
            }
        }
    }
};


int main() {
    Solution slt;
    vector<vector<char> > board(5);
    board[0] = { 'X', 'X', 'X', 'X', 'X', 'X', 'X'};
    board[1] = { 'X', 'O', 'O', 'X', 'X', 'X', 'X'};
    board[2] = { 'X', 'X', 'O', 'X', 'X', 'X', 'X'};
    board[3] = { 'X', 'X', 'X', 'X', 'X', 'X', 'X'};
    board[4] = { 'X', 'O', 'X', 'X', 'X', 'X', 'X'};
    slt.solve(board);
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
    board.resize(3);
    board[0] = { 'O', 'O', 'O'};
    board[1] = { 'O', 'O', 'O'};
    board[2] = { 'O', 'O', 'O'};
    slt.solve(board);
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            cout << board[i][j];
        }
        cout << endl;
    }


    return 0;
} 
