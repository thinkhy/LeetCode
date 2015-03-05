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
#include <climits>
#include <utility>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*******************************************************************************************************************
 *
 * Longest Palindromic Substring Total 
 *
 * Accepted: 27428 Total Submissions: 132818
 * 
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 * 
 *
 ************************************************************************************************************************/

class Solution {
    static const int MAGIC = 214748364;
public:
    int reverse(int x) {
       int res = 0; 
       while(x) {
         if (abs(res) > MAGIC) {
             return 0;
         }
         else {
             res = res * 10 + (x%10); 
             x /= 10;
         }
       }

       return res;
    }
};

int main() {
    Solution slt;
    DE(slt.reverse(0));
    DE(slt.reverse(100));
    DE(slt.reverse(-100));
    DE(slt.reverse(123));
    DE(slt.reverse(-123));

    DE(INT_MAX);
    DE(slt.reverse(INT_MAX));
    DE(INT_MIN);
    DE(slt.reverse(INT_MIN));
    return 0;
}






