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
#include <cstdio>
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
    int uniquePathsWithObstacles(vector< vector<int> > &grid) {

       if(grid.size() == 0 || grid[0].size() == 0 
           || grid[grid.size()-1][grid[0].size()-1] == 1) 
           return 0;

       int m = grid.size();
       int n = grid[0].size();

       vector< vector<int> > paths(m);

       int i,j;
       for(i = 0; i < m; i++)
           paths[i] = vector<int>(n, 0);

       bool flag = true;
       for(i = 0; i < m && grid[i][0] == 0; i++) 
           paths[i][0] = 1;
           
       for(i = 0; i < n && grid[0][i] == 0; i++) 
           paths[0][i] = 1;


 	   /**************************************
        *
        * s[r][c] = s[r-1][c] + s[r][c-1] 
        *
        **************************************/
       for(i = 1; i < m; i++)
           for(j = 1; j < n; j++) {
                if(grid[i][j] == 0) {
                    if(grid[i-1][j] == 0)
                        paths[i][j] += paths[i-1][j];
                    if(grid[i][j-1] == 0)
                        paths[i][j] += paths[i][j-1];
                }
           }
                    

       return paths[m-1][n-1];
    }
};


int main() {
    Solution s;
    int m;
    int n;
    int i;

    m = 0; n = 0;
    vector<vector<int> >  grid;

    grid.resize(m);
    for(i = 0; i < m; i++)
       grid[i] = vector<int>(n, 0);
    cout << s.uniquePathsWithObstacles(grid) << endl;

    m = 1; n = 0;
    grid.resize(m);
    for(i = 0; i < m; i++)
       grid[i] = vector<int>(n, 0);
    printf("m: %d  n: %d  paths: %d\n", 
            m, n, s.uniquePathsWithObstacles(grid));

    m = 0; n = 1;
    grid.resize(m);
    for(i = 0; i < m; i++)
       grid[i] = vector<int>(n, 0);
    printf("m: %d  n: %d  paths: %d\n", 
            m, n, s.uniquePathsWithObstacles(grid));

    m = 1; n = 1;
    grid.resize(m);
    for(i = 0; i < m; i++)
       grid[i] = vector<int>(n, 0);
    printf("m: %d  n: %d  paths: %d\n", 
            m, n, s.uniquePathsWithObstacles(grid));

    m = 2; n = 2;
    grid.resize(m);
    for(i = 0; i < m; i++)
       grid[i] = vector<int>(n, 0);
    printf("m: %d  n: %d  paths: %d\n", 
            m, n, s.uniquePathsWithObstacles(grid));

    m = 2; n = 1;
    grid.resize(m);
    for(i = 0; i < m; i++)
       grid[i] = vector<int>(n, 0);
    printf("m: %d  n: %d  paths: %d\n", 
            m, n, s.uniquePathsWithObstacles(grid));

    m = 1; n = 2;
    grid.resize(m);
    for(i = 0; i < m; i++)
       grid[i] = vector<int>(n, 0);
    grid[0][0] = 1;
    printf("m: %d  n: %d  paths: %d\n", 
            m, n, s.uniquePathsWithObstacles(grid));

    m = 3; n = 3;
    grid.resize(m);
    for(i = 0; i < m; i++)
       grid[i] = vector<int>(n, 0);
    grid[1][1] = 1;
    printf("m: %d  n: %d  paths: %d\n", 
            m, n, s.uniquePathsWithObstacles(grid));

    m = 3; n = 7;
    grid.resize(m);
    for(i = 0; i < m; i++)
       grid[i] = vector<int>(n, 0);
    printf("m: %d  n: %d  paths: %d\n", 
            m, n, s.uniquePathsWithObstacles(grid));

    m = 100; n = 50;
    grid.resize(m);
    for(i = 0; i < m; i++)
       grid[i] = vector<int>(n, 0);
    printf("m: %d  n: %d  paths: %d\n", 
            m, n, s.uniquePathsWithObstacles(grid));

    m = 40; n = 10;
    grid.resize(m);
    for(i = 0; i < m; i++)
       grid[i] = vector<int>(n, 0);
    printf("m: %d  n: %d  paths: %d\n", 
            m, n, s.uniquePathsWithObstacles(grid));

    n = 40; m = 10;
    grid.resize(m);
    for(i = 0; i < m; i++)
       grid[i] = vector<int>(n, 0);
    printf("m: %d  n: %d  paths: %d\n", 
            m, n, s.uniquePathsWithObstacles(grid));

    m = 1; n = 10;
    grid.resize(m);
    for(i = 0; i < m; i++)
       grid[i] = vector<int>(n, 0);
    printf("m: %d  n: %d  paths: %d\n", 
            m, n, s.uniquePathsWithObstacles(grid));
    
    return 0;
}





