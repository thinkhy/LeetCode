#include <iostream>
#include <sstream>
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
#include <cstdio>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << (a) << endl;

/************************************************************************************************************************
 *
 * Majority Element
 *
 * Given an array of size n, find the majority element. The majority element is the element that appears more than n/2 times.
 * 
 * You may assume that the array is non-empty and the majority element always exist in the array.
 *
 ************************************************************************************************************************/

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int len = num.size();
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int cnt =0;
            int cur = 1<<i;
            for(int k = 0; k < len; k++) {
                if(cur&num[k])
                    cnt++;
            }
            if(cnt > len/2)
                ans |= cur;
        }

        return ans;
    }
};

int main() {
    Solution slt;
    vector<int> num = {1, 1, 2, 1, 3};
    DE(slt.majorityElement(num));

    vector<int> num1 = {1};
    DE(slt.majorityElement(num1));

    return 0;
}


