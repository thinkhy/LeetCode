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
    int find_longest_pld(const string& s, int i, int j) {
        while(i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        return j-i-1;
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++) {
            int len1 = find_longest_pld(s, i, i);
            int len2 = find_longest_pld(s, i, i+1);
            int len = max(len1, len2);
            if(len > end - start) {
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }

        return s.empty() ? "" :  s.substr(start, end-start+1);
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
    s = "bb";
    DE(slt.longestPalindrome(s));
    return 0;
}






