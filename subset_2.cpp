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
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> re;    
        sort(S.begin(),S.end());
        re.push_back(vector<int>());
        for(int i=0;i<S.size(); ++i) {
            int size=re.size();
            for(int j=0;j<size;++j)
            {
                //vector<int> tmp=re[j];
                //tmp.push_back(S[i]);
                re.push_back(re[j]);
                re.back().push_back(S[i]);
            }
        }
        return re;
    }
};


int main() {
    Solution s;
    vector<int> m;
    m.resize(3);
    m[0] = 1;
    m[1] = 2;
    m[2] = 3;

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





