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
    int totalNQueens(int n) {
        int cnt = 0;
        if(n==0) return 0;

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
                cnt++;
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
        
        return cnt;
    }
};

int main() {
    Solution s;
    cout << s.totalNQueens(0) << endl;
    cout << s.totalNQueens(1) << endl;
    cout << s.totalNQueens(2) << endl;
    cout << s.totalNQueens(3) << endl;
    cout << s.totalNQueens(4) << endl;
    cout << s.totalNQueens(5) << endl;
    cout << s.totalNQueens(6) << endl;
    cout << s.totalNQueens(7) << endl;
    cout << s.totalNQueens(8) << endl;
    cout << s.totalNQueens(9) << endl;

    return 0;
}

