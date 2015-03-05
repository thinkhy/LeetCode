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
#include <cmath>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int binary_search(vector<int> &num, int low, int high) {
           if (low == high || num[low] < num[high]) 
               return num[low];

           int mid = (low+high)/2;
           if(num[mid] < num[low]) {
               return binary_search(num, low+1, mid);
           }
           else if(num[mid] > num[high]) {
               return binary_search(num, mid+1, high);
           }
           else {
               return min(binary_search(num, low, mid),
                          binary_search(num, mid+1, high));
           }
    }

    int findMin(vector<int> &num) {
        if(num.empty()) return 0;
        int low = 0;
        int high = num.size() - 1;

        return binary_search(num, low, high);
    }
};

int main() {
    Solution s;

    vector<int> nums(7);
    nums[0] = 4;
    nums[1] = 5;
    nums[2] = 6;
    nums[3] = 7;
    nums[4] = 0;
    nums[5] = 1;
    nums[6] = 2;

    cout << s.findMin(nums) << endl;
    nums.clear();
    nums.resize(5);
    nums[0] = 10;
    nums[1] = 1;
    nums[2] = 10;
    nums[3] = 10;
    nums[4] = 10;
    cout << s.findMin(nums) << endl;

    return 0;
}



