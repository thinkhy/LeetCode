#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

/*******************************************************************************************
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * You are given a target value to search. If found in the array return its index,
 * otherwise return -1. You may assume no duplicate exists in the array.
 *
 ******************************************************************************************/
class Solution {
public:
    int search(int a[], int n, int target) {
        if(n <= 0) return -1;
        int hit = -1;
        int low = 0;
        int high = n-1;
        int mid;
        while(low <= high) {
            mid = (low+high)/2;
            if(a[mid] == target)
                return mid;
            else if(a[low] < a[high]) {
                if(a[mid] > target) 
                    high = mid-1;
                else
                    low = mid+1;
            }
            else {
                if(target < a[high]) {
                    if(a[mid] < a[high]) {
                        if(a[mid]<target)
                            low=mid+1;
                        else 
                            high=mid-1;
                    }
                    else {
                        low = mid+1;
                    }
                }
                else {
                    if(a[mid] > a[low]) {
                        if(a[mid]<target)
                            low = mid+1;
                        else
                            high = mid-1;
                    }
                    else {
                        high = mid-1;
                    }
                }
            }
        }

        return hit;
    }
};


int main() {
    Solution s;    

    int r, t;
    int a[] = {4,5,6,7,0,1,2};
    r = s.search(a, sizeof(a)/sizeof(a[0]), 4); 
    cout << "target: " << t << " index: " << r << endl;

    return 0;
}






