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
        //binary-search row    
        int row = matrix.size();
        if(row == 0) return false;
        int col = matrix[0].size();

        int min, mid, max;
        min = 0;
        max = row - 1;
        mid = (min + max) / 2;

        while(min < max && min != mid) {
            if(matrix[mid][0] == target ) {
                return true;
            }
            else if(matrix[mid][0] < target ) {
                min = mid;
            }
            else {
                max = mid;
            }

            mid = (min + max)/2;
        }
        // cout << "min: " << min << endl;

        if(matrix[min][0] == target || matrix[max][0] == target) {
            return true;
        }

        mid = matrix[max][0] < target ? max: min;

        return binary_search(matrix[mid].begin(), matrix[mid].end(), target);
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



