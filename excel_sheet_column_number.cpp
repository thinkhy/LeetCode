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
#include <climits>
#include <utility>
#include <cstdio>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << (a) << endl;

/*******************************************************************************************************************
 *
 * Related to question Excel Sheet Column Title
 * 
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 *
 * For example:
 *
 *   A -> 1
 *   B -> 2
 *   C -> 3
 *   ...
 *   Z -> 26
 *   AA -> 27
 *   AB -> 28 
 *
 * Credits:
 *   Special thanks to @ts for adding this problem and creating all test cases.
 *
 ************************************************************************************************************************/
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            res = res*26 + (s[i]-'A'+1);
        }
        
        return res;
    }
};

int main() {
    Solution slt;

    DE(slt.titleToNumber("A"));
    DE(slt.titleToNumber("B"));
    DE(slt.titleToNumber("C"));
    DE(slt.titleToNumber("D"));
    DE(slt.titleToNumber("Z"));
    DE(slt.titleToNumber("ZZ"));
    DE(slt.titleToNumber("AA"));
    DE(slt.titleToNumber("ZA"));
    DE(slt.titleToNumber("AB"));

    return 0;
}

