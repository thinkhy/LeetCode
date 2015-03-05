#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

/*******************************************************************************************
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 * 
 * For example,
 * Given n = 3,
 * 
 * You should return the following matrix:
 *
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 *
 ******************************************************************************************/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
       int level = 0; 
       int cnt = 1; 
       int i;
       vector<vector<int> > m(n);
       for(i = 0; i < n; i++)
           m[i].resize(n);

       while(n > 0) { 
         for(i=level; i<n; i++)    m[level][i] = cnt++;
         for(i=level+1;i<n; i++)   m[i][n-1] = cnt++;
         for(i=n-2; i>=level; i--) m[n-1][i] = cnt++;
         for(i=n-2; i>level; i--)  m[i][level] = cnt++;

         level++;
         n--;
       }

       return m;
    }
};

int main() {
    Solution s;    

    int cnt = 0;
    vector<vector<int> > matrix;
    int n;
    for(n=0; n<10; n++) {
        matrix = s.generateMatrix(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << matrix[i][j]  << " ";
            }
            cout << endl;
        }
    }

    cout << endl;

    return 0;
}






