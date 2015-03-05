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
#include <cstdio>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &s) {
        vector<vector<int> > result;
        vector<int> cur;
        int  n = s.size();

        result.push_back(cur);
        sort(s.begin(), s.end());

        for(int k = 1; k <= n; k++) {
            cur.clear();
            for (int i = 0; i < k; ++i)
                cur.push_back(i+1);

            while (!cur.empty()) {
                int tail = cur.back();
                if (tail > n - k + cur.size()) {
                    cur.pop_back();
                    if (cur.empty())
                        break;
                    else
                        cur[cur.size()-1]++;
                } else if (cur.size() == k) {
                    vector<int> tmp;
                    for(int cnt = 0; cnt < k; cnt++) {
                        tmp.push_back(s[cur[cnt]-1]);
                    }
                    result.push_back(tmp);
                    cur[k-1]++;
                } else
                    cur.push_back(tail+1);
            }
        }

        return result;
    }
};


int main() {
    Solution s;
    vector<int> m;
    m.resize(0);
    //m[0] = 1;

    vector< vector<int> > r = s.subsets(m);
    cout << r.size() << endl;
    for(int i = 0; i < r.size(); i++)  {
        for(int j = 0; j < r[i].size(); j++) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}





