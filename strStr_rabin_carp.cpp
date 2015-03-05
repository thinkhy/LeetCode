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
#include <cstdlib>
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
        // to find the big prime number: http://www.bigprimes.net/archive/prime/100001/
        unsigned int q = 373591679;
        int m = strlen(needle);
        int n = strlen(haystack);
        if (m == 0 || n == 0 || m > n) 
            return m == 0 ? 0 : -1;

        //int d = 373591679;
        int d = 3;
        int t = haystack[0];
        int p = needle[0];
        int h = 1;

        // why we need a Prime?
        for(int i = 1; i < m; i++) {
            h = (h*d)%q;
            p = ((p*d)%q + needle[i])%q;
            t = ((t*d)%q + haystack[i])%q;
        }

        for(int i = 0; i <= n-m; i++) {
            if(p == t) {
                cout << "OK" << endl;
                int j = 0;
                for(; j < m && needle[j] == haystack[i+j]; j++);
                if(j == m) 
                    return i;
            }

            if(i < n-m)
                t = ((t-haystack[i]*h)*d + haystack[i+m])%q;
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
    char e[] = "baabbaaaaaaabbaaaaabbabbababaabbabbbbbabbabbbbbbabababaabbbbbaaabbbbabaababababbbaabbbbaaabbaababbbaabaabbabbaaaabababaaabbabbababbabbaaabbbbabbbbabbabbaabbbaa";
    char f[] = "bbaaaababa";
    DE(slt.strStr(e, f));

    return 0;
}






