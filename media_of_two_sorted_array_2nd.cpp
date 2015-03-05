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

/*
 * Median of Two Sorted Arrays
 *
 * There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 */

class Solution {
public:
    int find_k_element(int a[], int m, int b[], int n, int k) {
        if(m > n) 
            return find_k_element(b, n, a, m, k);
        if(m == 0)
            return b[k-1];
        if(k == 1)
            return min(a[0], b[0]);

        int ia = min(m, k/2);
        int ib = k-ia;
        if(a[ia-1] < b[ib-1])
            return find_k_element(a+ia, m-ia, b, ib, k-ia);
        else if(a[ia-1] > b[ib-1])
            return find_k_element(a, m, b+ib, n-ib, k-ib);
        else
            return a[ia-1];
    }

    double findMedianSortedArrays(int a[], int m, int b[], int n) {
        int total = m + n;
        if (total&0x01) 
            return find_k_element(a, m, b, n, 1+total/2);
        else {
            int first =  find_k_element(a, m, b, n, total/2);
            int second = find_k_element(a, m, b, n, 1+total/2);
            // note for arithmetical operation between 
            return (first + second) / 2.0;
        }

    }

};



int main() {
    Solution s;
    //int a[] = {};
    //int b[] = {2, 3};

    int a[] = {1,2};
    int b[] = {1,2};
    cout << s.findMedianSortedArrays(a, sizeof(a)/sizeof(*a), 
                                b, sizeof(b)/sizeof(*b)) << endl;

    return 0;
}



