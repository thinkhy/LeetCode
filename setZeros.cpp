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
    void setZeroes(vector<vector<int> > &matrix) {
        bool isRowZero, isColZero;
        isRowZero = isColZero = false;

        int row = matrix.size();
        if(row == 0) return;

        int col = matrix[0].size();
        if(col == 0) return;

        for(int i = 0; i < row; i++)
            if(matrix[i][0] == 0) {
                isColZero = true;
                break;
            }

        for(int i = 0; i < col; i++)
            if(matrix[0][i] == 0) {
                isRowZero = true;
                break;
            }

        for(int i = 1; i < row; i++)         
            for(int j = 1; j < col; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }

        for(int i = 1; i < row; i++)
            for(int j = 1; j < col; j++)
                if(matrix[i][0] == 0 || matrix[0][j] == 0) 
                    matrix[i][j] = 0;


        if(isColZero) {
            for(int i = 0; i < row; i++)
                matrix[i][0] = 0;
        }

        if(isRowZero) {
            for(int i = 0; i < col; i++)
                matrix[0][i] = 0;
        }
    }
};


int main() {
    Solution s;

    vector<vector<int> > m;
    m.resize(1);
    for(int i = 0; i < m.size(); i++)
        m[i] = vector<int>(2, 0);

    m[0][1] = 1;
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++)
            cout << m[i][j] << " ";
        cout << endl;
    }

    s.setZeroes(m);

    cout <<endl;

    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++)
            cout << m[i][j] << " ";
        cout << endl;
    }

    return 0;
}





