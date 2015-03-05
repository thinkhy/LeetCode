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
    void dfs(list<int> unusedNum, vector<vector<int> >& results,
             vector<int>& r, int depth) {
        if(depth == r.size()) {
            results.push_back(r);
            return;
        }

        list<int>::iterator it;
        for(it = unusedNum.begin(); it != unusedNum.end();) {
                r[depth] = *it;
                it = unusedNum.erase(it);
                dfs(unusedNum, results, r, depth+1);
                unusedNum.insert(it, r[depth]);
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > results;
        if(num.empty()) return results;

        vector<int> r(num.size());

        list<int> unusedNum(num.begin(), num.end());

        dfs(unusedNum, results, r, 0);            

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
    cout << "======" << endl;
    for(int i = 0; i < r.size(); i++) {
        for(int j = 0; j < r[0].size(); j++) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    num.clear();
    n = 10;
    num.resize(n);
    for(int i = 0; i < n; i++)
        num[i] = i+1;

    r = s.permute(num);
    cout << r.size() << endl;
    /*
    cout << "======" << endl;
    for(int i = 0; i < r.size(); i++) {
        for(int j = 0; j < r[0].size(); j++) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    */
    return 0;
}


