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
             vector<int> c,
             int n,
             int k,
             int curIndex, 
             int pos) {
        if(k == 0) {
            r.push_back(c);
            return;
        }

        for(int i = curIndex; i <= n-k; i++) {
            c[pos] = i+1;
            dfs(r, c, n, k-1, i+1, pos+1);
        }
    }

    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > r;
        vector<int> c(k);
        dfs(r, c, n, k, 0, 0);

        return r;
    }
};

void printCombine(vector<vector<int> > re) {
    for(int i = 0; i < re.size(); i++) {
        for(int j = 0; j < re[i].size(); j++) {
            cout << re[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution s;
    vector<vector<int> > re = s.combine(0,0);
    printCombine(re);
    re = s.combine(1,0);
    printCombine(re);
    cout << "# 1,1 # " << endl;
    re = s.combine(1,1);
    printCombine(re);
    cout << endl;
    cout << "# 1,2 # " << endl;
    re = s.combine(1,2);
    printCombine(re);
    cout << endl;
    re = s.combine(4,2);
    printCombine(re);

    return 0;
}


