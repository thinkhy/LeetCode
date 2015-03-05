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
 * Scrable string
 *
 * Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 * Below is one possible representation of s1 = "great":
 *  
 *      great
 *     /    \
 *    gr    eat
 *   / \    /  \
 *  g   r  e   at
 *             / \
 *            a   t
 *  To scramble the string, we may choose any non-leaf node and swap its two children.
 *  
 *  For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
 *  
 *      rgeat
 *     /    \
 *    rg    eat
 *   / \    /  \
 *  r   g  e   at
 *             / \
 *            a   t
 *  We say that "rgeat" is a scrambled string of "great".
 *  
 *  Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
 *  
 *      rgtae
 *     /    \
 *    rg    tae
 *   / \    /  \
 *  r   g  ta  e
 *         / \
 *        t   a
 * We say that "rgtae" is a scrambled string of "great".
 * 
 * Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 *
 ************************************************************************************************************************/
class Solution {
public:
    bool isScramble(string s1, string s2) {
       const int len = s1.size();
       if(len != s2.size())
           return false;

       bool f[len+1][len][len];
       fill_n(&f[0][0][0], (len+1)*len*len, false);
       for(int i = 0; i < len; i++) {
           for(int j = 0; j < len; j++) {
               f[1][i][j] = s1[i] == s2[j];
           }
       }

       for(int n = 2; n <= len; n++) 
           for(int i = 0; i+n <= len; i++) {
               for(int j = 0; j+n <= len; j++) {
                   for(int k = 1; k < n; k++) {
                       if((f[k][i][j]&&f[n-k][i+k][j+k])
                           || (f[k][i][j+n-k]&&f[n-k][i+k][j])) {
                           f[n][i][j] = true;
                           break; 
                       }
                   }
               }
           }

     return f[len][0][0];    
    }
};

int main() {
    Solution s;
    string s1, s2;
    s1 = "great";
    s2 = "rgeat";
    DE(s.isScramble(s1, s2));

    s2 = "rgtae";
    DE(s.isScramble(s1, s2));

    s1 = "abcd";
    s2 = "bdac";
    DE(s.isScramble(s1, s2));

    s1 = "abb";
    s2 = "bba";
    DE(s.isScramble(s1, s2));
    vector<int> test = {1, 2, 3, 4};

    return 0;
}


