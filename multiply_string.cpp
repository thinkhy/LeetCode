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
 * Multiply Strings
 *
 * https://oj.leetcode.com/problems/multiply-strings/
 *
 * Total Accepted: 18670 Total Submissions: 91017 
 *
 * Given two numbers represented as strings, 
 * return multiplication of the numbers as a string.
 *
 * Note: The numbers can be arbitrarily large and are non-negative.
 *
 ************************************************************************************************************************/

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();        
        int len2 = num2.size();        
        if(len1 == 0 || len2 == 0) 
            return "0";
        string res(len1+len2, 0);

        int i, j, k, carry;
        int digit_count = 0;
        for(i = len2-1; i>=0; i--) {
            for(j = len1-1; j>=0; j--) {
                int cur = len2-1-i+len1-1-j; 
                res[cur] = res[cur] + (num1[j]-'0') * (num2[i]-'0');
                // fixed after second submission
                if(res[cur] == 0) continue;

                digit_count = max(digit_count, cur);
                carry=0;
                k = cur;
                do {
                    int sum = res[k] + carry;
                    res[k] = sum%10;
                    carry = sum/10;
                } while(carry&&++k <= digit_count); 

                if(k>digit_count && carry) 
                    res[++digit_count] = carry;
            }
        }

        // if we didn't add this line, letcode will hit a defec!!
        res.resize(digit_count+1);
        // reserve string and restore numbers to characters
        for(i = 0, j = digit_count; i <= j; i++, j--) 
            swap(res[i], res[j]);
        for(i = 0; i <= digit_count; i++) 
            res[i] = res[i]+'0';
        

        return res;
    }
};

int main() {
    Solution slt;

    EXPECT(slt.multiply("0", "0"), "0");
    EXPECT(slt.multiply("1", "0"), "0");
    EXPECT(slt.multiply("1", "1"), "1");
    EXPECT(slt.multiply("2", "3"), "6");
    EXPECT(slt.multiply("11", "11"), "121");
    EXPECT(slt.multiply("100", "100"), "10000");
    EXPECT(slt.multiply("9133", "0"), "0");

    return 0;
}






