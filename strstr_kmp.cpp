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
 * Implement strStr() 
 *
 *   Total Accepted: 28594 Total Submissions: 131831
 * 
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * 
 * Update (2014-11-02):
 * The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.
 *
 ************************************************************************************************************************/

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        char *ps, *pp;
        ps = haystack;
        pp = needle;
        int lens = strlen(haystack);
        const int lenp = strlen(needle);

        if(lenp == 0)
            return 0;

        int next[lenp];
        int i,j;
        i=0;
        j = next[0] = -1;

        // calculate next array
        while(i<lenp) {
            while(j > -1 && needle[i] != needle[j]) {
                j = next[j];
            }
            i++;
            j++;
            if(needle[i] == needle[j]) 
                next[i] = next[j];
            else
                next[i] = j;
        }

        // KMP match 
        for(int j = 0, i = 0; i < lens;) {
            while(j > -1 && haystack[i] != needle[j])
                j = next[j];

            j++;
            i++;
            if(j == lenp)
                return i-lenp;
        }
                
        return -1;
    }
};

int main() {
    Solution slt;
    char a[] = "abcefe";
    char b[] = "cef";
    DE(slt.strStr(a ,b));
    char c[] = "a";
    char d[] = "a";
    DE(slt.strStr(c ,d));

    return 0;
}






