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

        return BM(haystack, lens, needle, lenp);
    }

    void preBmBc(char *x, int m, int bmBc[]) {
       int i;
     
       for (i = 0; i < ASIZE; ++i)
          bmBc[i] = m;
       for (i = 0; i < m - 1; ++i)
          bmBc[x[i]] = m - i - 1;
    }
     
     
    void suffixes(char *x, int m, int *suff) {
       int f, g, i;
     
       suff[m - 1] = m;
       g = m - 1;
       for (i = m - 2; i >= 0; --i) {
          if (i > g && suff[i + m - 1 - f] < i - g)
             suff[i] = suff[i + m - 1 - f];
          else {
             if (i < g)
                g = i;
             f = i;
             while (g >= 0 && x[g] == x[g + m - 1 - f])
                --g;
             suff[i] = f - g;
          }
       }
    }
     
    void preBmGs(char *x, int m, int bmGs[]) {
       int i, j, suff[XSIZE];
     
       suffixes(x, m, suff);
     
       for (i = 0; i < m; ++i)
          bmGs[i] = m;
       j = 0;
       for (i = m - 1; i >= 0; --i)
          if (suff[i] == i + 1)
             for (; j < m - 1 - i; ++j)
                if (bmGs[j] == m)
                   bmGs[j] = m - 1 - i;
       for (i = 0; i <= m - 2; ++i)
          bmGs[m - 1 - suff[i]] = m - 1 - i;
    }
     
     
    int BM(char *x, int m, char *y, int n) {
       int i, j, bmGs[XSIZE], bmBc[ASIZE];
     
       /* Preprocessing */
       preBmGs(x, m, bmGs);
       preBmBc(x, m, bmBc);
     
       /* Searching */
       j = 0;
       while (j <= n - m) {
          for (i = m - 1; i >= 0 && x[i] == y[i + j]; --i);
          if (i < 0) {
             return j;
             // j += bmGs[0];
          }
          else
             j += MAX(bmGs[i], bmBc[y[i + j]] - m + 1 + i);
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






