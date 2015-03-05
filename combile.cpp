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
    void dfs(vector<vector<int> >& r,
             vector<int> combine,
             int n,
             int k,
             int curIndex) {
        if(k == 0) 
            r.push_back(combine);

        for(int i = curIndex; i <= n-k; i++) {
            combine[curIndex] = i;
            dfs(r, combile, n, k-1, i+1);
        }
    }

    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > r;
        vector<int> c(k);
        r = dfs(r, c, n, k, 0);

        return r;
    }
};

void printCombine(vector<vector<int> > re) {
    for(int i = 0; i < re.size(); i++) {
        for(int j = 0; j < re[i]; j++) {
            cout << re[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution s;
    vector<vector<int> > re = s.combine(4,2);
    printCombine(re);

    return 0;
}


