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
 * Longest Palindromic Substring Total 
 *
 * Accepted: 27428 Total Submissions: 132818
 * 
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 * 
 *
 ************************************************************************************************************************/

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty() || s.size()==1)
            return s;

        int len = s.size();

        bool book[len][len+1];
        memset(book, 0, len*(len+1));
        for(int i = 0; i < s.size(); i++) {
            book[i][0] = book[i][1] = true;;
        }
        int max_size = 0;
        string res = "";

        for(int i = 2; i<=len; i++) {
            for(int j = 0; j+i<=len; j++) {
                if(s[j] == s[j+i-1] 
                        && book[j+1][i-2]) {
                    book[j][i] = true;
                    if(max_size < i) {
                        max_size = i;
                        res = s.substr(j, i);
                    }
                }
            }
        }

        
        return res;
    }
};

int main() {
    Solution slt;
    string s = "abcddcbb";
    DE(slt.longestPalindrome(s));
    s = "a";
    DE(slt.longestPalindrome(s));
    s = "aaabaaaaa";
    DE(slt.longestPalindrome(s));
    return 0;
}






