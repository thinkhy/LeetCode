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
        int cur = num[0];
        int count = 1;        
        for(int i = 1; i < num.size(); i++) {
            if(cur != num[i]) {
                count--;
                if(count == 0) {
                    cur = num[i];
                    count = 1;
                }
            }
            else 
                count++;
        }

        return cur;
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


