#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*
Implement wildcard pattern matching with support for '?' and '*'.

    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
    isMatch("aa","a") → false
    isMatch("aa","aa") → true
    isMatch("aaa","aa") → false
    isMatch("aa", "*") → true
    isMatch("aa", "a*") → true
    isMatch("ab", "?*") → true
    isMatch("aab", "c*a*b") → false
*/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *ss = s;
        const char *star = NULL;

        while(*s) {
            if(*p ==  *s || *p == '?') {
                p++; s++;
            }
            else if(*p == '*') {
               star = p++; 
               ss = s;
            }
            else if(star) {
                p = star + 1;
                s = ++ss;
            }
            else 
                return false;
        }

        while(*p == '*') p++;

        return *p == NULL;
    }
};

int main() {
    Solution s; 

    DE(s.isMatch("ab","?*"));
    DE(s.isMatch("aa","a"));
    DE(s.isMatch("aa","aa"));
    DE(s.isMatch("aaa","aa"));
    DE(s.isMatch("aa","*"));
    DE(s.isMatch("aa","a*"));
    DE(s.isMatch("ab","?*"));
    DE(s.isMatch("aab","c*a*b"));
    DE(s.isMatch("aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba",
                 "*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*"));

    DE(s.isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb",
                 "*aa*ba*a*bb*aa*ab*a*aaaaaa*a*aaaa*bbabb*b*b*aaaaaaaaa*a*ba*bbb*a*ba*bb*bb*a*b*bb"));

    cout << s.isMatch("a", "ab*") << endl;
    /*
    isMatch("aa","a") → false
    */
    cout << s.isMatch("aa", "a") << endl;
    /*
    isMatch("aa","aa") → true
    */
    cout << s.isMatch("aa", "aa") << endl;
    /*
    isMatch("aaa","aa") → false
    */
    cout << s.isMatch("aaa", "aa") << endl;
    /*
    isMatch("aa", "a*") → true
    */
    cout << s.isMatch("aa", "a*") << endl;
    /*
    isMatch("aa", ".*") → true
     */
    cout << s.isMatch("aa", "a*") << endl;
    /*
    isMatch("ab", ".*") → true
    */
    cout << s.isMatch("aa", "a*") << endl;
    /*
    isMatch("aab", "c*a*b") → true
    */
    cout << "=======================" << endl;
    cout << s.isMatch("aab", "c*a*b") << endl;
    cout << s.isMatch("aa", ".*c") << endl;
    cout << s.isMatch("a", "ab*") << endl;
    cout << s.isMatch("a", ".*..a*") << endl;
    cout << s.isMatch("aaaa", "") << endl;

    return 0;
}



