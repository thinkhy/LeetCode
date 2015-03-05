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
#include <algorithm>
#include <limits>
#include <utility>
#include <cstdio>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << (a) << endl;

/*******************************************************************************************************************
 *
 *  Fraction to Recurring Decimal 
 *
 *  Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
 *  
 *  If the fractional part is repeating, enclose the repeating part in parentheses.
 *  
 *  For example,
 *  
 *  Given numerator = 1, denominator = 2, return "0.5".
 *  Given numerator = 2, denominator = 1, return "2".
 *  Given numerator = 2, denominator = 3, return "0.(6)".
 *  Credits:
 *  Special thanks to @Shangrila for adding this problem and creating all test cases.
 *
 ************************************************************************************************************************/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // to optimize memory performance, replace osstream with the C string array
        char ans[5000];
        memset(ans, 0, 500);
        long long num;
        long long denom;

        // if denom equals 0, return a unlimited number
        if(numerator != 0 && denominator == 0)
          return "0";
        else if(numerator == 0)
          return "0";

        num = numerator;
        denom = denominator;
        if ((numerator>>31)^(denominator>>31)) 
            ans[0] = '-';

        // NOTE: if number equals -2147483648, -1*number will overflow.
        num = abs(abs);
        denom = abs(denom);

        long long quotient, modulus;
                            
        // first, try to divide num by denom 
        // if num is greater or equal than denom
        if(num >= denom) {
           quotient = num/denom; 
           modulus = num - denom*quotient;

           sprintf(ans+strlen(ans), "%lld", quotient);
           if(modulus == 0) 
               return ans;
        }
        // or num < denom, append "0." into result string
        else {
            modulus=num;
            ans[strlen(ans)]='0';
        }

        if(modulus != 0)
            ans[strlen(ans)]='.';

        // different thing is to handle number after decimal point
        // hashset: to record repeated num
        unordered_map<int, int> num_occur;
        while(modulus != 0) {
            // find the first number greater than denom 
            int cur_pos = strlen(ans);
            int carries = 0;

            num = modulus*10;
            while(num<denom) {
                num *= 10;
                carries++;

                // borrow a digit from right digit, append 0 into result string
                ans[strlen(ans)] = '0';
            }

            quotient = num/denom; 
            modulus = num - denom*quotient;

            // then append quotient 
            sprintf(ans+strlen(ans), "%lld", quotient);

            // hit the repeating number, enclose result in parathses 
            if(num_occur.find(num) != num_occur.end()) {
                int len = strlen(ans)-num_occur[num];
                for(int i = 0; i<len; i++)
                    ans[cur_pos-i] = ans[cur_pos-i-1]; 
                ans[cur_pos-len] = '(';
                ans[cur_pos+1] = ')';
                ans[cur_pos+2] = '\0';
                break;
            }
            else {
                num_occur[num] = strlen(ans);
            }

        }

        return ans;
    }
};

int main() {
    Solution slt;
    DE(slt.fractionToDecimal(-22, -2));
    DE(slt.fractionToDecimal(0, 3));
    DE(slt.fractionToDecimal(1, 99));
    DE(slt.fractionToDecimal(1, 6));
    DE(slt.fractionToDecimal(1, 2));
    DE(slt.fractionToDecimal(2, 1));
    DE(slt.fractionToDecimal(2, 3));
    DE(slt.fractionToDecimal(2, 3000));
    DE(slt.fractionToDecimal(200, 3000));
    DE(slt.fractionToDecimal(200, 200));
    DE(slt.fractionToDecimal(-2147483648, 1));

    return 0;
}

