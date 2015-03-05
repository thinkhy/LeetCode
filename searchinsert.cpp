#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n <= 0) return 0;
        int low = 0;
        int high = n-1;
        int mid;
        while(low <= high) { 
            mid = (low+high)/2;
            if (A[mid] > target) {
                high = mid - 1;
            }
            else if (A[mid] < target) {
                low = mid + 1;
            }
            else {
                return mid;
            }
        }
        if (A[mid] > target) 
            return mid; 
        else 
            return mid+1;

    }
};

int main() {
    Solution s;
    int a[] = {1,3,5,6};
    int n = 4;
    int target;
    target = 5;
    cout << s.searchInsert(a, n, 5) << endl;
    cout << s.searchInsert(a, n, 2) << endl;
    cout << s.searchInsert(a, n, 7) << endl;
    cout << s.searchInsert(a, n, 0) << endl;

    int b[] = {1,3};
    cout << s.searchInsert(b, 2, 2) << endl;

}
