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
    double findMedianSortedArrays(int a[], int m, int b[], int n) {
        int *aa = a;
        int *bb = b;
        int median;

        if(aa[0] > bb[0]) {
            swap(aa, bb);
            swap(m, n);
        }

        if(aa[m-1] < bb[0]) {
            // medium in the array A
            if(m > n) {
                median = (m+n)%2 ? aa[(m+n)/2] : (aa[(m+n)/2]+aa[(m+n)/2-1])/2;
            }
            // medium in the array B
            else if(m < n) {
                median = (m+n)%2 ? bb[(m+n)/2-m] : (bb[(m+n)/2-m]+bb[(m+n)/2-m-1])/2;
            }
            // medium between B and A
            else { 
                median = (a[m-1]+b[0])/2;
            }
        }
        // A and B are interleaving
        else {
            int mm = find_k_element(aa, bb[0]);
            if(mm > (m+n)/2) {
                median = (m+n)%2 ? aa[(m+n)/2] : (aa[(m+n)/2]+aa[(m+n)/2-1])/2;
                return median;
            }
            
            int nn = find_k_element(bb, aa[m-1]);
            if(n-nn > (m+n)/2) {
                int mid = n - (m+n)/2;
                median = (m+n)%2 ? bb[mid] : (bb[mid]+bb[mid-1])/2;
                return median;
            }

            int mid = findKSortedArrays(aa+mm, m-mm, bb, nn, ); 
            

        }

        return median;
    }
};



int main() {
    Solution s;
    int a[] = {5, 6,7};
    int b[] = {1, 3};

    cout << s.findMedianSortedArrays(a, sizeof(a)/sizeof(*a), 
                                b, sizeof(b)/sizeof(*b)) << endl;

    return 0;
}



