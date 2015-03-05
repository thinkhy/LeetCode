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
 * Merge k Sorted Lists 
 *
 * There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. 
 * The overall run time complexity should be O(log (m+n)).
 *
 * To find the median, 
 *      refer to: http://www.wikihow.com/Find-the-Median-of-a-Set-of-Numbers
 *
 */

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int findKthElement(int *a, int m, int *b, int n,
                        int k) {
        if(m>n)
            return findKthElement(b,n, a,m, k);
        if(m==0)
            return b[k-1];
        if(k==1)
            return min(a[0], b[0]);

        int pa = min(k/2, m);
        int pb = k-pa;
        if(a[pa-1] > b[pb-1])
            return findKthElement(a, m, b+pb, n-pb, k-pb);
        else if(a[pa-1] < b[pb-1])
            return findKthElement(a+pa, m-pa, b, n, k-pa);
        else
            return a[pa-1];
    }

    double findMedianSortedArrays(int a[], int m, int b[], int n) {
        int size = m+n;
        if(size&1)
            return findKthElement(a, m, b, n, size/2 + 1);
        else
            return (findKthElement(a, m, b, n, size/2)
                    + findKthElement(a, m, b, n, size/2 + 1))/2.0;
    }
};



int main() {
    Solution s;
    int a[] = {2, 4};
    int b[] = {1, 3, 5};

    cout << s.findMedianSortedArrays(a, sizeof(a)/sizeof(*a), 
                                b, sizeof(b)/sizeof(*b)) << endl;

    return 0;
}



