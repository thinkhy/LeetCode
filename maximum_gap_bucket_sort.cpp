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

       int min_num = INT_MAX;
       int max_num = INT_MIN;
       for(int i = 0; i < len; i++) {
           if (min_num > num[i])
               min_num = num[i];
           if (max_num < num[i])
               max_num = num[i];
       }

       // let the length of a bucket to be len = ceiling[(B-A)/(N-1)], then we will have at most num = (B-A)/len + 1 of bucket
       int bucket_len = (max_num-min_num+len-2)/(len-1);
       int bucket_num = (max_num-min_num)/bucket_len+1;

       // for any number K in the array, we can easily find out which bucket 
       // it belongs by calculating loc=(K-A)/len and therefore maintain 
       // the maximum and minimum elements in each bucket
       vector<vector<int>> buckets(bucket_num);

       // bucket sort
       // STEP 1: distribute numbers into buckets
       for(int i = 0; i<len; i++) {
           int index = (num[i]-min_num)/bucket_len;
           if(buckets[index].empty()) {  // initially max = min = num[i]
               buckets[index].push_back(num[i]);
               buckets[index].push_back(num[i]);
           }
           else {                    // else compare and update
               buckets[index][0] = min(buckets[index][0], num[i]);
               buckets[index][1] = max(buckets[index][1], num[i]);
           }
       }


       // Since the maximum difference between elements in the same buckets 
       // will be at most len - 1, so the final answer will not be taken from 
       // two elements in the same buckets.
       // For each non-empty buckets p, find the next non-empty buckets q,
       // then q.min - p.max could be the potential answer to the question.
       // Return the maximum of all those values.
       ans = bucket_len-1;
       int last_valid_bucket = -1;
       for(int i = 0; i < bucket_num; i++) {
           if(!buckets[i].empty()) {
               if(last_valid_bucket >= 0)
                   ans = max(ans, buckets[i][0] - buckets[last_valid_bucket][1]);
               last_valid_bucket = i;
           }
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

