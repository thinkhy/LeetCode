#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstdio>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << (a) << endl;
#define EXPECT(a, b) cout << #a << ": result: " << (a) \
                                << "  expect: " << (b)   << endl;

/*******************************************************************************************************************
 *
 * Factorial Trailing Zeros
 * 
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 *  Note: Your solution should be in logarithmic time complexity.
 * 
 *  Credits:
 *   Special thanks to @ts for adding this problem and creating all test cases.
 *
 *
 ************************************************************************************************************************/

class Solution {
public:
    int trailingZeroes(int n) {
        int num5 = 0;   
        for( int i = 2; i <= n; i++ )
        {
            int t = i;
            while( t && t % 5 == 0 )
            {
                num5++;
                t /= 5;
            }
        }
        return num5;
    }
};

int main() {
    Solution slt;
    slt.trailingZeroes(20);
                
    return 0;
}

