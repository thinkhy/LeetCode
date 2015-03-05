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
    A peak element is an element that is greater than its neighbors.

    Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

    The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

    You may imagine that num[-1] = num[n] = -∞.

    For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

    click to show spoilers.

    Note:
    Your solution should be in logarithmic complexity.

    Credits:
    Special thanks to @ts for adding this problem and creating all test cases.
 ************************************************************************************************************************/

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
       int len = num.size(); 
       int low = 0, high = len-1;;

       while(low < high) {
           int mid = (low + high)/2;
           if(num[mid] < num[mid+1]) {
              low = mid+1;
           }
           else {
              high = mid; 
           }
       }

       return low;
    }
};

int main() {
    Solution slt;
    vector<int> num = {1, 2, 3, 1};
    DE(slt.findPeakElement(num));

    vector<int> num1 = {1};
    DE(slt.findPeakElement(num1));

    vector<int> num2 = {1,0};
    DE(slt.findPeakElement(num2));

    vector<int> num3 = {1,0,1};
    DE(slt.findPeakElement(num3));

    vector<int> num31 = {1,2,3};
    DE(slt.findPeakElement(num31));

    vector<int> num32 = {3,2,1};
    DE(slt.findPeakElement(num32));

    return 0;
}






