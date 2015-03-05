#include <iostream>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
using namespace std;



class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.empty()) return 0;

        int m = grid.size();

        int n = grid[0].size();
        if(n==0) return 0;

        int i; 

        for(i = 1; i < m; i++) 
           grid[i][0] += grid[i-1][0];
        for(i = 1; i < n; i++) {
           grid[0][i] += grid[0][i-1];
        }
        
       int level = 1;
       while(level < m && level < n) {
           grid[level][level] += min(grid[level-1][level], grid[level][level-1]);
           for(i = level+1; i < m; i++)
               grid[i][level] += min(grid[i][level-1], grid[i-1][level]);

           for(i = level+1; i < n; i++)
               grid[level][i] += min(grid[level-1][i], grid[level][i-1]);

           level++;
       }

       /*
       if(level < m && n >= 2) {
           for(i = level; i < m; i++)
               grid[i][n-1] += min(grid[i-1][n-1], grid[i][n-2]);
       }
       else if(level < n && m >= 2) {
           for(i = level; i < n; i++) {
               cout << "grid[m-1][i]: " << grid[m-1][i] << endl;
               grid[m-1][i] += min(grid[m-1][i-1], grid[m-2][i]);
               cout << "grid[m-1][i-1]: " << grid[m-1][i] << endl;
               cout << "grid[m-2][i]: " << grid[m-2][i] << endl;
               cout << "grid[m-1][i]: " << grid[m-1][i] << endl;
           }
       }
       */

       return grid[m-1][n-1];
    }
};


int main() {
    Solution s;
    vector<vector<int> > grid;
    int m,n;
    m = 1;
    n = 2;
    vector<int> row(n, 1);
    for(int i = 0; i < m; i++)
        grid.push_back(row);

    cout << s.minPathSum(grid) << endl;

    return 0;
}





