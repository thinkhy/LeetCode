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
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if (numRows <= 0) return result;        

        for(int i = 0; i < numRows; i++) {
            vector<int> row(i+1);
            row[0] = row[i] = 1;

            for(int j = 1; j < i; j++) 
                row[j] = result[i-1][j-1] + result[i-1][j];

            result.push_back(row);
        }
    }
};

int main() {
    Solution s;
    for(int k = 0; k <10; k++) {
        vector<vector<int> > result =  s.generate(k);
        for(int i = 0; i < result.size(); i++) {
            for(int j = 0; j < result[i].size(); j++)
                cout << result[i][j] << " ";

            cout << endl;
        }
        cout << endl;
    }

    return 0;
}


