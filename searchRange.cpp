#include <iostream>
#include <string>
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
    vector<int> searchRange(int a[], int n, int target) {
        vector<int> r;
        
        int left, right;
        int low0, high0, mid0, low, high, mid;

        // first run, binary-find the target
        low0 = 0; high0 = n-1;
        while(low0 <= high0) {
           mid0 = (low0+high0) / 2;
           if(a[mid0] == target)
               break;
           else if(a[mid0] > target)
               high0 = mid0 - 1;
           else
               low0 = mid0 + 1;
        }

        // the target is not found, return [-1, -1]
        if(low0 > high0) {
            r.push_back(-1);
            r.push_back(-1);
            return r;
        }

        // target is found in the array, go ahead
        
        // find the left part

        left=right=mid0;
        low = low0; 
        high = mid0-1;
        while(low <= high) {
            mid = (low+high) / 2;
            if(a[mid] == target) {
                left = mid;
                high = mid - 1;
            }
            else if(a[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        low = mid0+1;
        high = high0;
        while(low <= high) {
            mid = (low+high) / 2;
            if(a[mid] == target) {
                right = mid;
                low = mid + 1;
            }
            else if(a[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        r.push_back(left);
        r.push_back(right);

        return r;
    }
};


int main() {
    Solution s;
    vector<int> r;

    int a0[] = {};
    r = s.searchRange(a0, sizeof(a0)/sizeof(*a0), 8); 

    /* Print path vector to console */
    std::copy(r.begin(), r.end(), 
            std::ostream_iterator<int>(std::cout, " "));
    cout << endl;

    int a[] = {5, 7, 7, 8, 8, 10};
    r = s.searchRange(a, sizeof(a)/sizeof(*a), 8); 

    /* Print path vector to console */
    std::copy(r.begin(), r.end(), 
            std::ostream_iterator<int>(std::cout, " "));
    cout << endl;

    int a1[] = {5, 7, 7, 8, 10};
    r = s.searchRange(a1, sizeof(a1)/sizeof(*a1), 8); 

    /* Print path vector to console */
    std::copy(r.begin(), r.end(), 
            std::ostream_iterator<int>(std::cout, " "));
    cout << endl;
    
    return 0;
}





