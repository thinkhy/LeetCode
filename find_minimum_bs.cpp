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

/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.empty()) return 0;
        int low = 0;
        int high = num.size() - 1;
        int mid;

        while(low < high) {
            mid = (low + high)/2;
            if(num[low]>num[mid]) {
                low++;
                high=mid;
            }
            else if(num[mid] > num[high]) {
                low = ++mid; 
            }
            else
                high = mid; 
        }

        return num[low];
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
    nums.resize(2);
    nums[0] = 2;
    nums[1] = 1;
    cout << s.findMin(nums) << endl;

    return 0;
}



