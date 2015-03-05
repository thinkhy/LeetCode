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
       if(s1.size() != s2.size())
           return false;

       int len = s1.size();

       if(len == 1) {
           return s1[0] == s2[0];
       }
       else if(len == 2) {
           return s1==s2 || (s1[0] == s2[1] && s1[1] == s2[0]);
       }
       else {
           string tmp1 = s1;
           string tmp2 = s2;
           sort(tmp1.begin(), tmp1.end());
           sort(tmp2.begin(), tmp2.end());
           if(tmp1 != tmp2)
               return false;

           for(int i = 0; i < len-1; i++) {
                // partite s1 from postion i+1
                string s1_left  = s1.substr(0, i+1);
                string s1_right = s1.substr(i+1);
                string s2_left  = s2.substr(0, i+1);
                string s2_right = s2.substr(i+1);
                string s2_left_reverse = s2.substr(len-i-1);
                string s2_right_reverse  = s2.substr(0, len-i-1);

                if((isScramble(s1_left,s2_left) 
                            && isScramble(s1_right, s2_right))
                    || (isScramble(s1_right, s2_right_reverse) 
                            && isScramble(s1_left, s2_left_reverse))) { 
                    return true;
                }
           }
       }

       return false;
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

    for(int i = 0; i < test.size(); i++) {
        cout << test[i] << endl;
    }
    typedef string::const_iterator Iterator;
    map<tuple<Iterator, Iterator, Iterator>, bool> cache;

    return 0;
}


