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
#include <utility>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*******************************************************************************************************************
 *
 * https://oj.leetcode.com/problems/palindrome-number/
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * click to show spoilers.
 * 
 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 * 
 * If you are thinking of converting the integer to string, note the restriction of using extra space.
 * 
 * You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
 * 
 * There is a more generic way of solving this problem.
 *
 **********************k**************************************************************************************************/

class Solution {
    public:
       bool isPalindrome(int x) {
           int digit = 1;
           int num = x;
           while(num=num/10) { 
               digit *= 10;
           }

           num = x;
           while(num) {
               if (num/digit != num%10) 
                    return false;
               num = num%digit
               digit /= 100; 
           }

           return true;
       }
};

int main() {
    Solution slt;

    // corner case
    DE(slt.isPalindrome(""));

    // corner case
    DE(slt.isPalindrome("0"));

    // expected result: failed
    DE(slt.isPalindrome("123"));

    // expected result: success
    DE(slt.isPalindrome("321123"));

    // overflow
    DE(slt.isPalindrome("22211111111111222"));

    // overflow
    DE(slt.isPalindrome("11111111111111111"));

    // overflow
    DE(slt.isPalindrome("21111111111111111"));

    return 0;
}






