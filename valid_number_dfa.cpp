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
        enum InputType {
            INVALID,   
            SPACE,
            SIGN,
            DIGIT,
            DOT,
            EXPONENT,
            NUM_INPUTS
        };
        const int transitionTable[][NUM_INPUTS] = {
            -1, 0, 3, 1,  2, -1,
            -1, 8,-1, 1,  4, 5,  
            -1, -1,-1, 4, -1, -1,
            -1, -1,-1, 1, 2,  -1,
            -1, 8, -1, 4, -1, 5,
            -1, -1, 6, 7, -1, -1,
            -1, -1, -1,7, -1, -1,
            -1, 8, -1, 7, -1, -1,
            -1, 8, -1, -1,-1, -1,
        };
        int state = 0;
        for(; *s != '\0'; ++s) {
            InputType inputType = INVALID;
            if (isspace(*s)) 
                inputType = SPACE;
            else if (*s == '+' || *s == '-')
                inputType = SIGN;
            else if (isdigit(*s)) 
                inputType = DIGIT;
            else if(*s == '.')
                inputType = DOT;
            else if(*s == 'e' || *s == 'E')
                inputType = EXPONENT;

            state = transitionTable[state][inputType];

            // invalid input
            if (state == -1) return false;
        }

    return state == 1 || state == 4 || state == 7 || state == 8;
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






