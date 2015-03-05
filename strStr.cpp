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
        int lenp = strlen(needle);

        for(int i = 0; i <= lens - lenp; i++) {
            int k = 0;
            while(haystack[i+k] && haystack[i+k] == needle[k]) k++;
            if(k == lenp)
                return i;
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






