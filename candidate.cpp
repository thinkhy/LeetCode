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
    void dfs(vector<vector<int> >& results, 
             vector<int> s, 
             const vector<int>& candidates, 
             int startpos,
             int target) {
        for(int i = startpos; i < candidates.size(); i++) {
            if(target - candidates[i] < 0)
                break;

            s.push_back(candidates[i]);

            if(target == candidates[i]) 
                results.push_back(s);
            else  {
                dfs(results, s, candidates, i, target - candidates[i]);
            }

            s.pop_back();
        }

        return;
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
       vector<vector<int> > results; 
       vector<int> s; 

       sort(candidates.begin(), candidates.end()); 
       dfs(results, s, candidates, 0, target); 

       return results;
    }
};

int main() {
    Solution s;
     
    vector<vector<int> > re;
    vector<int> candidates;
    int target;

    candidates.clear();
    candidates.resize(4);
    candidates[0] = 2;
    candidates[1] = 3;
    candidates[2] = 6;
    candidates[3] = 7;
    target = 7;

    re = s.combinationSum(candidates, target);
    for(int i = 0; i < re.size(); i++) {
        for(int j = 0; j < re[i].size(); j++) {
            cout << re[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}



