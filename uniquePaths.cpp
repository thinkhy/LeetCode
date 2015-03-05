#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
using namespace std;


/*************************************************************
 *
 * A robot is located at the top-left corner of a m x n grid 
 * (marked 'Start' in the diagram below).  The robot can only 
 * move either down or right at any point in time. The robot 
 * is trying to reach the bottom-right corner of the grid 
 * (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 *
 *	   s[r][c] = s[r-1][c] + s[r][c-1];
 *     s[r][0] = r;
 *	   s[0][c] = c;
 *
 ************************************************************/
class Solution {
public:
    int uniquePaths(int m, int n) {
       if(m == 0 || n ==0) return 0;
       vector< vector<int> > paths(m);

       int i;
       for(i = 0; i < m; i++)
           paths[i].resize(n);

       for(i = 0; i < m; i++) 
           paths[i][0] = 1;
       for(i = 1; i < n; i++) 
           paths[0][i] = 1;

       int level = 1;
       while(level < m && level < n) {
           paths[level][level] = paths[level-1][level]+paths[level][level-1];
           for(i = level+1; i < m; i++)
               paths[i][level] = paths[i][level-1]+paths[i-1][level];
           for(i = level+1; i < n; i++)
               paths[level][i] = paths[level-1][i]+paths[level][i-1];

           level++;
       }

       if(level < m && n > 1) {
           for(i = level; i < m; i++)
               paths[i][n-1] = paths[i-1][n-1]+paths[i][n-2];
       }
       else if(level < n && m > 1) {
           for(i = level; i < n; i++)
               paths[m-1][i] = paths[m-1][i-1]+paths[m-2][i];
       }

       return paths[m-1][n-1];
    }
};


int main() {
    Solution s;
    int m;
    int n;

    m = 0; n = 0;
    cout << s.uniquePaths(m,n) << endl;

    m = 1; n = 0;
    cout << s.uniquePaths(m,n) << endl;

    m = 0; n = 1;
    cout << s.uniquePaths(m,n) << endl;

    m = 1; n = 1;
    cout << s.uniquePaths(m,n) << endl;

    m = 2; n = 2;
    cout << s.uniquePaths(m,n) << endl;

    m = 2; n = 1;
    cout << s.uniquePaths(m,n) << endl;

    m = 1; n = 2;
    cout << s.uniquePaths(m,n) << endl;

    m = 3; n = 3;
    cout << s.uniquePaths(m,n) << endl;

    m = 3; n = 7;
    cout << s.uniquePaths(m,n) << endl;

    m = 100; n = 50;
    cout << s.uniquePaths(m,n) << endl;

    m = 40; n = 10;
    cout << s.uniquePaths(m,n) << endl;

    n = 40; m = 10;
    cout << s.uniquePaths(m,n) << endl;

    m = 1; n = 10;
    cout << s.uniquePaths(m,n) << endl;
    
    
    return 0;
}





