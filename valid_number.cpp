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
#include <memory>
#include <limits>
#include <utility>
#include <cstdio>
#include <cstring>
#include <climits>      // for INT_MAX
using namespace std;

#define DE(a) cout << #a << ": " << (a) << endl;
#define EXPECT(a, b) cout << #a << ": result: " << (a) \
                                << "  expect: " << (b) << endl;

/*******************************************************************************************************************
 *
 * Valid Number
 *
 * https://oj.leetcode.com/problems/valid-number/
 *
 * Validate if a given string is numeric.
 * 
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 *************************************************************************************************************************/

class Solution {
public:
    bool isNumber(const char *s) {
         bool ans = true;
         char *p = (char*)s;

         // ignore leading space
         bool start_with_number = false;

         while(*p == ' ') p++;  
         if(*p == '+' || *p == '-') p++;
         if(*p <= '9' && *p >= '0') start_with_number = true;
         while(*p <= '9' && *p >= '0') p++;

         if(*p == '.') { 
             p++;
             if(*p <= '9' && *p >= '0') start_with_number = true;
             while(*p <= '9' && *p >= '0') p++;
         }
              
         if(*p == 'e' || *p == 'E') {
             if(start_with_number == false)
                 return false;
             p++;
             if(*p == '+' || *p == '-') p++;
             start_with_number = (*p <= '9' && *p >= '0');
             while(*p <= '9' && *p >= '0') p++;
         }

         while(*p == ' ') p++;
          
         return start_with_number&&*p == '\0';
    }
};

int main() {
    Solution slt;

    EXPECT(slt.isNumber(" "),    false);
    EXPECT(slt.isNumber(".1"),   true);
    EXPECT(slt.isNumber("-1."),   true);
    EXPECT(slt.isNumber("0"),    true);
    EXPECT(slt.isNumber("0e"),    false);
    EXPECT(slt.isNumber("0.1"),  true);
    EXPECT(slt.isNumber("abc"),  false);
    EXPECT(slt.isNumber("1 a"),  false);
    EXPECT(slt.isNumber("2e10"), true);
    EXPECT(slt.isNumber(" 005047e+6"), true);

    return 0;
}






