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
#include <limits>
#include <climits>
#include <utility>
#include <cstdio>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << (a) << endl;

/*******************************************************************************************************************
 *
 * Minimum Window Substring
 * 
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 * 
 * For example,
 *  S = "ADOBECODEBANC"
 *  T = "ABC"
 *  Minimum window is "BANC".
 * 
 * Note:
 *  If there is no such window in S that covers all characters in T, return the emtpy string "".
 *  If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 *
 ************************************************************************************************************************/

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.size() < t.size())
            return "";

        // maintain two indices, the right index moves from left to right 
        // the left index is minimum position of substring containing the charaters in T
        // if all the characters in T are all matched up, the minimun size of window may be adjusted
        int min_size = INT_MAX;
        string substring;

        // define two maps to store expected number and appeared number of characters in string T
        int expected[256];  // the number of character of T in the string S
        int appeared[256];  // the number of character in string T appeared

        fill_n(expected, 256, 0);
        fill_n(appeared, 256, 0);

        // fill all the characters of t into the map
        for(int i = 0; i < t.size(); i++) {
            expected[t[i]]++;
        }

        int left, right;
        int cnt = 0;   // total number of charater appeared

        for(int right = 0; right < s.size(); right++) {
           char cur = s[right];

           // find the character contained in the string T
           if(expected[cur] > 0) { 
               // if current character is insufficicent, increace counter
              if(appeared[cur]++ < expected[cur]) {
                  cnt++;
                  // if cur is the first valid character we meet in S, set left position to right
                  if(cnt == 1)
                      left = right;
              }
              // else, if current character is as same as the character at the left-most of window, move left-most index 
              else if(s[left] == cur) {
                  while(expected[s[left]] == 0 || appeared[s[left]] > expected[s[left]]) {
                      if(expected[s[left]] > 0)
                          appeared[s[left]]--;
                      left++;
                  }
              }

              // if left index is changed, we need to update window size
              if(cnt == t.size() && min_size > right - left + 1) {
                  min_size = right - left + 1;
                  substring = s.substr(left, min_size);
              }


           }
        }

        return substring;
    }
};

int main() {
    Solution slt;
    DE(slt.minWindow("acbbaca", "aba"));
    DE(slt.minWindow("AA", "AA"));
    DE(slt.minWindow("", "ABC"));
    DE(slt.minWindow("A", "ABC"));
    DE(slt.minWindow("ABC", "A"));
    DE(slt.minWindow("A", "A"));
    DE(slt.minWindow("ADOBECODEBANC", ""));
    DE(slt.minWindow("ADOBECODEBANC", "ABC"));
    DE(slt.minWindow("ADOBECODEBANC", "ABCF"));

    return 0;
}

