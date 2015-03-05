#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/**
 * 4Sum
 * Given an array S of n integers, are there elements a, b, c, 
 * and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 *
 * For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 * 
 *     A solution set is:
 *     (-1,  0, 0, 1)
 *     (-2, -1, 1, 2)
 *     (-2,  0, 0, 2)
 *
 **/
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        
        return 0;
    }
}

int main() {
    Solution s;
    vector<int> num;
    num.resize(6);
    num[0] = 1;
    num[1] = 0;
    num[2] = -1;
    num[3] = 0;
    num[4] = -2;
    num[5] = 2;

    int target = 0;
    vector<vector<int> > re = s.fourSum(num, target);
    for(int i = 0; i < re.size(); i++) {
        for(int j = 0; j < 4; j++) {
            cout << re[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


