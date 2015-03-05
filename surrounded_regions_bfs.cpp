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
    int row;
    int col;
    vector<pair<int, int> > move_step; 

    void bfs(vector<vector<char> > &board, int r, int c) {
        queue<pair<int, int> > qe;
        qe.push({r, c});

        while(!qe.empty()) {        
            r = qe.front().first;
            c = qe.front().second;
            qe.pop();
            for(int i = 0; i < 4; i++) {
                int rr = r + move_step[i].first;
                int cc = c + move_step[i].second; 
                if(rr >= 0 && rr < row
                        && cc >= 0 && cc < col
                         && board[rr][cc] == 'O') {
                    board[rr][cc] = '+';
                    qe.push({rr, cc});
                }
            }
        }

        return;
    }

    void solve(vector<vector<char> > &board) {
        if (board.empty())
            return;
                                         
        row = board.size();        
        col = board[0].size();        

        move_step.resize(4);
        move_step[0] = {0,-1};
        move_step[1] = {0,1};
        move_step[2] = {-1,0};
        move_step[3] = {1,0};

        // BFS from four edges and mark cells not surrounded(dead) with '+' sign
        // top edge
        for(int i = 0; i < col; i++) {
            if(board[0][i] == 'O') {
                board[0][i] = '+';
                bfs(board, 0, i);
            }
        }

        // bottom edge
        for(int i = 0; i < col; i++) {
            if(board[row-1][i] == 'O') {
                board[row-1][i] = '+';
                bfs(board, row-1, i);
            }
        }
        
        // left edge
        for(int i = 1; i < row-1; i++) {
            if(board[i][0] == 'O') {
                board[i][0] = '+';
                bfs(board, i, 0);
            }
        }

        // right edge
        for(int i = 1; i < row-1; i++) {
            if(board[i][col-1] == 'O') {
                board[i][col-1] = '+';
                bfs(board, i, col-1);
            }
        }
        
        // then scan all the cells, recover live cells and flip dead cells 
        for(int i = 0; i < row; i++) 
            for(int j = 0; j < col; j++) {
                char cur = board[i][j];
                // recover live cell marked with '+' to 'O'
                if(cur == '+') 
                    board[i][j] = 'O';
                // flip dead cell into '*'
                else if(cur == 'O') 
                    board[i][j] = 'X';
            }

        return;
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

    vector<string> bs = {"OOOOOOOOXOOOOOXOOOOO",
                         "OOOOOOOXOOOOOOOOOOOO",
                         "XOOXOXOOOOXOOXOOOOOO",
                         "OOOOOOOOOOOOOOOOOXXO",
                         "OXXOOOOOOXOOOOOOOOOO",
                         "OOOOXOOOOOOXOOOOOXXO",
                         "OOOOOOOXOOOOOOOOOOOO",
                         "OOOOOOOOOOOOOXOOOOOO",
                         "OOOOOOOOOOOOOOOOOOXO",
                         "OOOOOXOOOOOOOOOOOOOO",
                         "OOOOOOOOXOOOOOOOOOOO",
                         "OOOOXOOOOXOOOOOOOOOO",
                         "OOOOOOOOXOOOOOOOOOOO",
                         "XOOOOOOOOXXOOOOOOOOO",
                         "OOOOOOOOOOOXOOOOOOOO",
                         "OOOOXOOOOOOOOXOOOOOX",
                         "OOOOOXOOOOOOOOOXOXOO",
                         "OXOOOOOOOOOOOOOOOOOO",
                         "OOOOOOOOXXOOOXOOXOOX",
                         "OOOOOOOOOOOOOOOOOOOO"};

    board.clear();
    for(int i = 0; i < bs.size(); i++) {
        vector<char> tmp;
        for(int j = 0; j < bs[i].size(); j++) {
            tmp.push_back(bs[i][j]);
        }
        board.push_back(tmp);
    }
    slt.solve(board);
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
} 
