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
 * Longest Substring Without Repeating Characters Total 
 *
 *    Accepted: 31873 Total Submissions: 144416 
 *
 * Given a string, find the length of the longest substring without repeating characters.
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc",
 * which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 *
 ************************************************************************************************************************/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int existed[256];
        fill_n(existed, 256, -1);

        int len = s.size();
        int j = 0;
        for(int i = 0; i < len; i++) {
            if(existed[s[i]] >= 0) {
                ans = max(ans, i-j);
                j = max(j, existed[s[i]]+1);
            }
            existed[s[i]] = i;
        }

        return max(ans, len-j);
    }
};

int main() {
    Solution slt;

    string s;

    s="abba";
    cout << s << ": " << slt.lengthOfLongestSubstring(s) << endl;

    s="cdd";
    cout << s << ": " << slt.lengthOfLongestSubstring(s) << endl;

    s="aa";
    cout << s << ": " << slt.lengthOfLongestSubstring(s) << endl;

    s="au";
    cout << s << ": " << slt.lengthOfLongestSubstring(s) << endl;

    s="a";
    cout << s << ": " << slt.lengthOfLongestSubstring(s) << endl;

    s="abcabcbb";
    cout << s << ": " << slt.lengthOfLongestSubstring(s) << endl;

    s="bbbbb";
    cout << s << ": " << slt.lengthOfLongestSubstring(s) << endl;

    s="ruowzgiooobpple";
    cout << s << ": " << slt.lengthOfLongestSubstring(s) << endl;

    return 0;
}






