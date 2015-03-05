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
    int singleNumber(int A[], int n) {
        int ones=0;
        int twos=0;
        int threes=0;

        for(int i = 0; i < n; i++) {
            twos |= ones&A[i];
            ones ^= A[i];    
            threes = ones&twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        
        return ones;
    }
};

int main() {
    Solution s;
    int a[] = {1,2,1,1,3,3,3};
    int n = sizeof(a)/sizeof(int);
    cout << s.singleNumber(a, n) << endl;

    return 0;
}


