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

/*********************************************************************************************
 * String to Integer (atoi)
 *
 *  https://oj.leetcode.com/problems/string-to-integer-atoi/
 *
 * Implement atoi to convert a string to an integer.
 * 
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 * 
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 * 
 * spoilers alert... click to show requirements for atoi.
 * 
 * Requirements for atoi:
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 *
 *********************************************************************************************/
class Solution {
public:
    int atoi(const char *str) {
        // the algo is simple but we need to think about some corner cases        
        // 1> consider limitation: n < INT_MIN or n > INT_MAX
        // 2> consider first sequence of non-whitespace is  invalid charater: str[i] > '9' str[i] < '0'
        // 3> consider initial plus '+' or minus sign '-'
        // 4> consider NULL string
        // ignore whitespace
        int res = 0;
        int i = 0;
        int sign=1;

        while(str[i]&&str[i] == ' ') i++;
        if(str[i] == '+') {
            sign = 1;
            i++;
        }
        else if(str[i] == '-') {
            sign = -1;
            i++;
        }
        /* If the first sequence of non-whitespace characters in str is not a valid integral number, 
         * or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed. */
        for(;str[i]&&str[i]>='0'&&str[i]<='9'; i++) {
            if((INT_MAX-(str[i]-'0'))/10 < res) // exceed numeric limitation
                return sign > 0 ? INT_MAX : INT_MIN; 
            else
                res = res * 10 + (str[i] - '0');
        }

        return sign*res;
    }
};


int main() {
    Solution slt;

    EXPECT(slt.atoi("-1"), -1);
    EXPECT(slt.atoi("1234"), 1234);
    EXPECT(slt.atoi("+1234"), 1234);
    EXPECT(slt.atoi("-1234"), -1234);
    EXPECT(slt.atoi("123a"), 123);
    EXPECT(slt.atoi(""), 0);
    EXPECT(slt.atoi("a123"), 0);
    EXPECT(slt.atoi("99999999999999999999999"), INT_MAX);
    EXPECT(slt.atoi("-99999999999999999999999"), INT_MIN);
    EXPECT(slt.atoi("-2147483648"), INT_MIN);

    return 0;
} 



