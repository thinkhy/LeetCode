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

#define DE(a) cout << #a << ": " << a << endl;


/*
    Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

    Each number in C may only be used once in the combination.

    Note:
    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
    The solution set must not contain duplicate combinations.
    For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
    A solution set is: 
    [1, 7] 
    [1, 2, 5] 
    [2, 6] 
    [1, 1, 6]
*/

class Solution {
public:
    void do_work(vector<vector<int> >& results, 
                 vector<int> &num, 
                 vector<int> selected,
                 int target,
                 int index) {
        if(target == 0) {
            results.push_back(selected);
            return;
        }

        int cur = 0;
        for(int i = index; i < num.size() && target >= num[i]; i++) {
           if(num[i] == cur) continue;
           cur = num[i];
           selected.push_back(cur);
           do_work(results, num, selected, target-cur, i+1); 
           selected.pop_back();
        }

        return;
    }
        
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
       sort(num.begin(), num.end());             

       vector<vector<int> > results;
       vector<int> selected;
       do_work(results, num, selected, target, 0);                             

       return results;
    }
};


int main() {
    Solution s;

    vector<int> num(7);
    int target;

    num.resize(7);
    num[0] = 10; num[1] = 1; num[2] = 2; num[3] = 7; 
    num[4] = 6; num[5] = 1;  num[6] = 5; 
    target = 8;
     
    vector<vector<int> > results = s.combinationSum2(num, target);
    for(int i = 0; i < results.size(); i++) {
        for(int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
        
    return 0;
}







