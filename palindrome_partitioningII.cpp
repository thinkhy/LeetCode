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
#include <climits> // for INT_MAX
using namespace std;

#define DE(a) cout << #a << ": " << (a) << endl;
#define EXPECT(a, b) cout << #a << ": result: " << (a) \
                                << "  expect: " << (b)   << endl;

/*********************************************************************************************
 *
 * Palindrome Partitioning II
 *
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * 
 * For example, given s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 *
 *********************************************************************************************/

class Solution {
public:
    bool isPalindrome(const string & str) {
        int i = 0;
        int j = str.size() - 1;
        while(i<j&&str[i++] == str[j--]);
        return j<=0 || i == j;
    }

    int minCut(string s) {
       const int len = s.size();
       cout << len << endl;
       vector<vector<bool>> pal(len, vector<bool>(len, false));
       int cut[len+1];
       //memset(pal, 0, len*len*sizeof(bool));
       if(s.empty() || s.size() == 1) return 0;

       cut[0] = -1;
       for(int i = 1; i <= len; i++) {
           cut[i] = i-1;
           pal[i-1][i-1] = true;
       }

       for(int i = 2; i <= len; i++) {
           for(int j = 0; j+i <= len; j++) {
               pal[j][j+i-1] = (i==2||pal[j+1][j+i-2]) && s[j]==s[j+i-1];
           }
       }
       for(int i = 2; i <= len; i++) {
           for(int j = 0; j < i; j++) {
               if(pal[j][i-1]) {
                   cut[i] = min(cut[i], cut[j]+1);
               }
           }
       }

       return cut[len];
    }
};

int main() {
    Solution s;
    EXPECT(s.minCut(""), 0); 
    EXPECT(s.minCut("a"), 0); 
    EXPECT(s.minCut("aa"), 0); 
    EXPECT(s.minCut("aab"), 1); 
    EXPECT(s.minCut("aabc"), 2); 
    EXPECT(s.minCut("cbaabc"), 0); 
    EXPECT(s.minCut("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"), 0); 
    
    return 0;
}



