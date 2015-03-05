#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
#include <iterator>
#include <cstdio>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int> > & results,
             vector<int> num,
             vector<int> s
             ) {
        if(num.empty()) {
            results.push_back(s);
            return;
        }

        int len = num.size();
        for(int i = 0; i < len; i++) {
            if(i > 0 && num[i] == num[i-1]) 
                continue;
            else {
                vector<int> s1 = s;
                vector<int> num1 = num;
                s1.push_back(num1[i]);
                num1.erase(num1.begin() + i);
                dfs(results, num1, s1);
            }
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());                
        vector<vector<int> > results;
        vector<int> s;

        dfs(results, num, s);

        return results;
    }
};


int main() {
    Solution s;

    vector<int> tmp;
    tmp.resize(3);
    tmp[0] = 1; tmp[1] = 1; tmp[2] = 2;
    vector<vector<int> > results = s.permuteUnique(tmp);
    for(int i = 0; i < results.size(); i++) {
        for(int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}



