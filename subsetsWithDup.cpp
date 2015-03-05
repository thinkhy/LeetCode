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
    vector<vector<int> > subsetsWithDup(vector<int> &s) {
        vector<vector<int> > re(1);
        re[0] = vector<int>();

        sort(s.begin(), s.end());
         
        vector<vector<int> > newAdded;
        for(int i = 0; i < s.size(); i++) {
            if(i > 0 && s[i] == s[i-1]) {
                for(int j = 0; j < newAdded.size(); j++) {
                    newAdded[j].push_back(s[i]);
                    re.push_back(newAdded[j]);
                }
            }
            else {
                newAdded.clear();
                int len = re.size();
                for(int j = 0; j < len; j++) {
                    vector<int> subset = re[j];
                    subset.push_back(s[i]);
                    re.push_back(subset);
                    newAdded.push_back(subset);
                }
            }
        }

        return re;
    }
};

void print(vector<vector<int> > re ) {
    for(int i = 0; i < re.size(); i++) {
        for(int j = 0; j < re[i].size(); j++) {
            cout << re[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution s;
    
    vector<int> a(3);
    a[0] = 2;
    a[1] = 2;
    a[2] = 1;

    vector<vector<int> > re = s.subsetsWithDup(a);
    print(re);

    return 0;
}






