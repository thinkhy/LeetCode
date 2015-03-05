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
    int maxSubArray(int A[], int n) {
        if(n==0) return 0;
        int last = A[0];
        int maxsum = last;
        for(int i = 1; i < n; i++) {
            if(last+A[i]>A[i])
                last += A[i];
            else
                last = A[i];
            if(last > maxsum)
                maxsum = last;
        }
        
        return maxsum;
    }
};

int main() {
    Solution s;
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(a)/sizeof(int);
    cout << s.maxSubArray(a, n) << endl;
    cout << s.maxSubArray(a, 1) << endl;

    return 0;
}


