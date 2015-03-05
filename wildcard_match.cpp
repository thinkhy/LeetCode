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
    bool match(const char *s, int s_len,
               const char *p, int p_len,
               int   s_pos,   int p_pos,
               int   star_match) {
        //DE(star_match);
        // all pattern matched
        if(p_pos >= p_len && s_pos >= s_len)     
            return true;

        // left string can't match with that START requires
        if(star_match < 0 || s_pos + star_match > s_len) 
            return false;

        // match single character
        if(p[p_pos] == '?') {
           if(s_pos < s_len)
               return match(s, s_len, p, p_len, s_pos+1, p_pos+1, star_match); 
           else
               return false;
        }
        // match any character(s)
        else if(p[p_pos] == '*') {
            // merge continued STAR
            while(p[p_pos+1] == '*') p_pos++;

            // match left string with *
            for(int i = star_match; i >= 0; i--) {
                if(match(s, s_len, p, p_len, s_pos+i, p_pos+1, star_match-i))
                    return true;
            }
        }
        // match a specific character
        else if(s[s_pos] == p[p_pos]) {
           return match(s, s_len, p, p_len, s_pos+1, p_pos+1, star_match); 
        }

        return false;
    }

    bool isMatch(const char *s, const char *p) {
        int s_len = strlen(s);
        int p_len = strlen(p);

        int cnt = 0;
        for(int i = 0; i < p_len; i++) {
           if(p[i] == '*') 
               cnt++;
        }

        int star_match = s_len - p_len + cnt;

        return match(s, s_len, p, p_len, 0, 0, star_match);
    }
};

int main() {
    Solution s; 

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



