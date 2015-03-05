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
        int occur[256];
        fill_n(occur, 256, -1);
        int res = 0;
        int start = 0;

        for(int i = 0; i < s.size(); i++) {
            int index = s[i];
            if(-1 != occur[index]) 
                start=max(occur[index]+1, start);

            occur[index] = i;
            res = max(i-start+1, res);
        }

        return res;
    }
};

int main() {
    Solution slt;
    string s;

    s="abcabcbb";
    cout << s << ": " << slt.lengthOfLongestSubstring(s) << endl;

    s="bbbbb";
    cout << s << ": " << slt.lengthOfLongestSubstring(s) << endl;

    s="ruowzgiooobpple";
    cout << s << ": " << slt.lengthOfLongestSubstring(s) << endl;
    return 0;
}






