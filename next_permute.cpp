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
using namespace std;

class Solution {
public:
    bool next_permute(vector<int> &num) {
        int len = num.size();
        int i, j;
        for(i = len-1; i > 0 && num[i] <= num[i-1]; i--); 
        if(i == 0)
            return false;

        for(j = i; j < len && num[j] > num[i-1]; j++);
        swap(num[i-1], num[j-1]);
        reverse(num.begin()+i, num.end());

        return true;
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > results;
        if(num.empty()) return results;

        sort(num.begin(), num.end());
        results.push_back(num);
        while(next_permute(num)) {
            results.push_back(num);
        }

        return results;
    }
};

int main() {
    Solution s;
    vector<int> num;
    vector<vector<int> > r;
    int n;

    num.clear();
    n = 3;
    num.resize(n);
    for(int i = 0; i < n; i++)
        num[i] = i+1;

    r = s.permute(num);
    for(int i = 0; i < r.size(); i++) {
        for(int j = 0; j < r[i].size(); j++)
            cout << r[i][j] << " ";
        cout << endl;
    }

    return 0;
}


