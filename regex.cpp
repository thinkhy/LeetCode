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


/* Regular Expression Matching 
 
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/
class Solution {
public:
    bool match(const char *s, int s_len, const char *p, 
               int p_len, int s_pos, int p_pos) {
        /*
        DE(s_len);
        DE(s_pos);
        DE(s[s_pos]);
        DE(p_len);
        DE(p_pos);
        DE(p[p_pos]);
        */
        if (s_pos >= s_len && p_pos >= p_len)
            return true;
        else if(p_pos >= p_len)
            return false;

        if(p[p_pos] == '.' && s_pos < s_len) 
            return match(s, s_len, p, p_len, s_pos+1, p_pos+1);
        else if(p[p_pos] == '*') {
            if(p_pos == 0 || p[p_pos-1] == '*')
                return false;
            else {
                int pos = s_pos-1;
                int c = p[p_pos-1];
                while(s[++pos] && (c == '.' || c == s[pos]));
                for(int i = pos; i >= s_pos-1; i--) {
                    if(match(s, s_len, p, p_len, i, p_pos+1)) {
                        return true;
                    }
                }
            }
        }
        else {
            if(s[s_pos] == p[p_pos])
                return match(s, s_len, p, p_len, s_pos+1, p_pos+1);
            else if(p[p_pos+1] == '*')  
                return match(s, s_len, p, p_len, s_pos, p_pos+2);
        }

        return false;
    }

    bool isMatch(const char *s, const char *p) {
       int s_pos = 0, p_pos = 0;
       int s_len = strlen(s);
       int p_len = strlen(p);

       return match(s, s_len, p, p_len, s_pos, p_pos); 
    }
};

int main() {
    Solution s; 

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



