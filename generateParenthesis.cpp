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

/************************************************
 *
 * Given n pairs of parentheses, 
 * write a function to generate all combinations 
 * of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:

 * "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 ************************************************/
class Solution {
public:
    void dfs(int n, int matched, int unclosed, 
             vector<string>& results, string r) {
        if(matched == n) {
            results.push_back(r);
            return;
        }

        string str;
        if(matched + unclosed < n) {
            str = r + "(";
            dfs(n, matched, unclosed+1, results, str);
        }

        if(unclosed > 0) {
            str = r + ")";
            dfs(n, matched+1, unclosed-1, results, str);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> results;
        if(n == 0) return results;

        string r;
        dfs(n, 0, 0, results, r);

        return results;
    }

};

int main() {
    Solution s;
    vector<string> r;
    int n;

    for(n = 0; n<5; n++) {
        r = s.generateParenthesis(n);
        for(int i = 0; i < r.size(); i++) {
            cout << r[i] << endl;
        }
        cout << endl;
    }


    return 0;
}





