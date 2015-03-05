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

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
       int row = matrix.size();

       if (row == 0) 
           return vector<int>();

       int column = matrix[0].size();
    
       vector<int> result;
       int r0=0, c0=0; 
       int r,c;
       bool hmove=false, vmove=false;

       while(r0 < row && c0 < column) {
           r = r0; c = c0;
           result.push_back(matrix[r][c]);

           // travel from left to right
           while(c+1 < column) {
               c++;
               result.push_back(matrix[r][c]);
               hmove=true;
           }

           
           // travel from top to bottom
           while(r+1 < row) {
               r++;
               result.push_back(matrix[r][c]);
               vmove=true;
           }

           if (hmove && vmove) {
               // travel from right to left
               while(c-1 >= c0 ) {
                   c--;
                   result.push_back(matrix[r][c]);
               }

               // travel from bottom to top
               while(r-1 > r0 ) {
                   r--;
                   result.push_back(matrix[r][c]);
               }
           }

           r0=r;
           c0=c+1;
           row = row - 1;
           column = column - 1;
           hmove=vmove=false;
       }
        
       return  result;
    }
};


int main() {
    Solution s;    

    int cnt = 0;
    vector<vector<int> > matrix;
    for(int i = 0; i < 3; i++) {
        vector<int> row(3);
        for(int j = 0; j < 3; j++) {
            row[j] = ++cnt;
        }
        matrix.push_back(row);
    }

    vector<int> result = s.spiralOrder(matrix);
    cout << endl;
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << "  ";
    }
    cout << endl;

    matrix.clear();
    result.clear();
    cnt = 0;
    for(int i = 0; i < 1; i++) {
        vector<int> row(2);
        for(int j = 0; j < 2; j++) {
            row[j] = ++cnt;
        }
        matrix.push_back(row);
    }

    result = s.spiralOrder(matrix);
    cout << endl;
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << "  ";
    }
    cout << endl;
    return 0;
}






