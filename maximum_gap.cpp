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

/*******************************************************************************************************************
 *
 * Maximum Gap 
 *
 * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 *
 * Try to solve it in linear time/space.
 * Return 0 if the array contains less than 2 elements.
 * You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 *
 ************************************************************************************************************************/

class Solution {
public:
    int maximumGap(vector<int> &num) {
       int ans = 0; 
       int len = num.size();
       if(len < 2) return 0;
       if(len == 2) return abs(num[0] - num[1]);

       int max_num = *max_element(num.begin(), num.end());
       vector<list<int>> buckets(10);

       // radix sort
       int base = 10;
       for(int d = 1; d <= max_num; d *= base) {
           // distribute number into buckets
           for(int k = 0; k < len; k++) {
               buckets[num[k]/d%base].push_back(num[k]);
           }
           // put back elements from buckets
           int k = 0;
           for(int i = 0; i < base; i++) {
               for(auto it = buckets[i].begin(); it != buckets[i].end(); it++) {
                    num[k++] = *it;
               }
               buckets[i].clear();
           }
       }

       for(int i = 1; i < len; i++) {
           ans = max(ans, abs(num[i] - num[i-1]));
       }

       return ans;
    }

};


int main() {
    Solution slt;
    vector<int> num = {1,5,3,10};
    DE(slt.maximumGap(num));

    vector<int> num1 = {2,999999,99999999};
    DE(slt.maximumGap(num1));
    return 0;
}

