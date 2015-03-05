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
    int findMin(vector &num) { 
        if (num.size() == 0) { 
            return -1; 
        }

        int start = 0;
        int end = (int)num.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (num[mid] < num[mid - 1] && num[mid] < num[mid + 1]) {
                return num[mid];
            } else if ((num[start] < num[mid]) && num[mid] < num[end]) {
                end = mid;
            } else if (num[start] < num[mid]) {
                start = mid;
            } else if (num[mid] < num[end]) {
                end = mid;
            }

        }

        if (num[start] < num[end]) {
            return num[start];
        } else {
            return num[end];
        }
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



