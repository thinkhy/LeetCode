#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*
 *
 * Maximal Rectangle 
 *
 * Given a 2D binary matrix filled with 0's and 1's, 
 * find the largest rectangle containing all ones and return its area.
 *   
 *  000000
 *  011110
 *  011110  
 *  011010
 *  011000 
 *
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()) return 0;

        int row = matrix.size();
        int column = matrix[0].size();
        int maxRect = 0;            

        vector<int> rowHeight(column+1, 0);

        for(int i = 0; i < matrix.size(); i++) {
            // canculate height for a row
            for(int j = 0; j < column; j++) {
                if(matrix[i][j] == '0')
                    rowHeight[j] = 0;
                else
                    rowHeight[j]++;
            }

            // find the maximal rect in current row
            stack<int> st;
            for(int j = 0; j <= column; j++) {
                int cur = rowHeight[j];
                while(!st.empty() && rowHeight[st.top()] > cur) {
                    int index = st.top();
                    st.pop();
                    int area = (st.empty() ? j : j-st.top()-1) * rowHeight[index];
                    if(area > maxRect)
                        maxRect = area;
                }
                st.push(j);
            }
        }

        return maxRect;
    }
};

int main() {
    Solution s;

    vector<vector<char> > m;
    m.clear();
    m.resize(4);
    for(int i = 0; i < m.size(); i++)
        m[i].resize(5);

    m[0][0] = '0'; m[0][1] = '0'; m[0][2] = '0'; m[0][3] = '0'; m[0][4] = '0';
    m[1][0] = '0'; m[1][1] = '1'; m[1][2] = '1'; m[1][3] = '1'; m[1][4] = '0';
    m[2][0] = '0'; m[2][1] = '1'; m[2][2] = '1'; m[2][3] = '1'; m[2][4] = '0';
    m[3][0] = '0'; m[3][1] = '0'; m[3][2] = '0'; m[3][3] = '0'; m[3][4] = '0';

    DE(s.maximalRectangle(m));

    return 0;
}



