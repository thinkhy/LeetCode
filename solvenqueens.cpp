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

        stack<pair<int, int> > st;
        st.push(make_pair(0,0));
        r[0][0] = 'Q';
        queens[0] = 0;

        int i,j;
        int x = 0, y = 1; // x: horizontal axis, y: vertical axis 
        while(y!=0 || x<n) {
            bool backtrace = false;

            // find a solution
            if (y==n) {
                results.push_back(r);
                backtrace=true;
            }
            else  {
                for(i = x; i < n; i++) {
                    for(j = 0; j < y; j++) {
                        // another Queen in the same colume
                        // or in the same 45 degree slope
                        if(abs(queens[j]-i) == abs(j-y) || queens[j] == i) { 
                            break;
                        }
                    }
                    // no other queen conflicts with pos(i,y) 
                    if(j==y) { 
                        r[i][y]='Q';
                        queens[y] = i;
                        st.push(make_pair(i, y));
                        x = 0; y++;
                        break;
                    }
                }

                // after iteration of colum x for row y
                if (i == n) {
                    backtrace=true;
                }
            }

            // backtrace to last row
            if(backtrace) {
                pair<int, int> pos = st.top();
                st.pop();
                x = pos.first;
                y = pos.second;
                r[x][y] = '.';
                queens[y] = -1;
                x++;
            }
        }
        
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


