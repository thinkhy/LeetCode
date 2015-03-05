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

class Solution {
public:
    void dfs(vector<vector<string> >& results, vector<string>& qmap, vector<int>& queens, int n, int row) {
        int i,j;
        for(i=0; i<n; i++) { 
            for(j=0; j<row; j++) {
                if(queens[j] == i || abs(queens[j]-i) == abs(j-row)) 
                    break;
            }
            if(j==row) {
                qmap[i][row] = 'Q';
                queens[row] = i;

                if(row == n-1) 
                    results.push_back(qmap);
                else
                    dfs(results, qmap, queens, n, row+1);

                qmap[i][row] = '.';
                queens[row] = -1;
            }
        }

        return;
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > results;
        if(n==0) return results;

        vector<string> r(n);
        for(int i = 0; i < n; i++) {
            r[i].resize(n);
            for(int j = 0; j < n; j++) {
                r[i][j] = '.';
            }
        }

        vector<int> queens(n);
        for(int i = 0; i < queens.size(); i++) 
            queens[i] = -1;

        dfs(results, r, queens, n, 0);

        return results;
    }
};


void printResult(const vector<vector<string> > r) {
    for(int i = 0; i < r.size(); i++) {
        for(int j = 0; j < r[i].size(); j++)
            cout << r[i][j] << endl;
        cout << endl;
    }
}

int main() {
    Solution s;
    vector<vector<string> > r1 = s.solveNQueens(0);
    printResult(r1);

    r1 = s.solveNQueens(0);
    printResult(r1);
    cout << "==================================" << endl;
    r1 = s.solveNQueens(1);
    printResult(r1);
    cout << "==================================" << endl;
    r1 = s.solveNQueens(2);
    printResult(r1);
    cout << "==================================" << endl;
    r1 = s.solveNQueens(3);
    printResult(r1);
    cout << "==================================" << endl;
    r1 = s.solveNQueens(4);
    printResult(r1);
    cout << "==================================" << endl;
    r1 = s.solveNQueens(5);
    printResult(r1);
    return 0;
    cout << "==================================" << endl;
    r1 = s.solveNQueens(6);
    printResult(r1);
    cout << "==================================" << endl;
    r1 = s.solveNQueens(7);
    printResult(r1);
    cout << "==================================" << endl;
    r1 = s.solveNQueens(8);
    printResult(r1);
    cout << "==================================" << endl;
}


