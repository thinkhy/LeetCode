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
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size();
        if(row == 0) return false;
        int col = matrix[0].size();

        int min, mid, max;
        min = 0;
        max = row * col - 1;

        while(min <= max) {
            mid = (min + max)/2;
            int r = mid / col;
            int c = mid % col;
            if(matrix[r][c] == target ) {
                return true;
            }
            else if(matrix[r][c] < target ) {
                min = mid + 1;
            }
            else {
                max = mid - 1;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int> > matrix;
    int r = 3, c = 4;
    for(int i = 0; i < r; i++) {
        matrix.push_back(vector<int>(c));
    }
    matrix[0][0] = 1;
    matrix[0][1] = 3;
    matrix[0][2] = 4;
    matrix[0][3] = 7;

    matrix[1][0] = 10;
    matrix[1][1] = 11;
    matrix[1][2] = 16;
    matrix[1][3] = 20;

    matrix[2][0] = 23;
    matrix[2][1] = 30;
    matrix[2][2] = 34;
    matrix[2][3] = 50;
    int target = 30;

    cout << s.searchMatrix(matrix, target) << endl;

    matrix.clear();
    matrix.push_back(vector<int>(1));
    matrix[0][0] = 1;
    target = 2;
    cout << s.searchMatrix(matrix, target) << endl;
    matrix.clear();
    cout << s.searchMatrix(matrix, target) << endl;

    matrix.push_back(vector<int>(1));
    matrix.push_back(vector<int>(1));
    matrix[0][0] = 1;
    matrix[1][0] = 3;
    target = 3;
    cout << s.searchMatrix(matrix, target) << endl;


    return 0;
}



