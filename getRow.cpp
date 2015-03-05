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
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        if (rowIndex < 0) return result;        

        vector<int> row(rowIndex+1);
        result.resize(rowIndex+1);

        for(int i = 0; i <= rowIndex; i++) {
            row[0] = row[i] = 1;

            for(int j = 1; j < i; j++) 
                row[j] = result[j-1] + result[j];

            result = row;
        }

        return result;
    }
};

int main() {
    Solution s;
    for(int i = 0; i <= 10; i++) {
        vector<int> r = s.getRow(i);
        for(int j = 0; j < r.size(); j++) { 
            cout << r[j] << " ";
        }
        cout << endl;
    }


    return 0;
}
