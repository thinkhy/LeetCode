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
#include <algorithm>
#include <limits>
#include <utility>
#include <cstdio>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << (a) << endl;

/*******************************************************************************************************************
 *
 *  Excel Sheet Column Title
 *
 *  Given a non-zero positive integer, return its corresponding column title as appear in an Excel sheet.
 *  For example:
 * 
 *     1 -> A
 *     2 -> B
 *     3 -> C
 *     ...
 *     26 -> Z
 *     27 -> AA
 *     28 -> AB 
 *     51 -> AY
 *     52 -> AZ
 *
 ************************************************************************************************************************/

class Solution {
public:
    string convertToTitle(int n) {
      string res;  
      if(n<1) return "";    

      int q, r;  // q: quotient, r: remainder

      // divide by 26 and insert the character regarding to modulus into the result.
      q = n;
      while(q > 26) {
          // get quotient and remainder
          r = q%26;
          q = q/26;

          // remainder is 0, reduce quotient by ONE because we need to fill a 'Z' here
          if(r == 0) {
              q--;
              res.insert(res.begin(), 1, 'Z');
          }
          else
              res.insert(res.begin(), 1, 'A'+r-1);
      }
      res.insert(res.begin(), 1, 'A'+q-1);

      return res;
    }
};

int main() {
    Solution slt;
    DE(slt.convertToTitle(INT_MAX));
    DE(slt.convertToTitle(0));
    DE(slt.convertToTitle(1));
    DE(slt.convertToTitle(2));
    DE(slt.convertToTitle(3));
    DE(slt.convertToTitle(26));
    DE(slt.convertToTitle(27));
    DE(slt.convertToTitle(28));
    DE(slt.convertToTitle(52));
    DE(slt.convertToTitle(55552));
    DE(slt.convertToTitle(27*26));

    return 0;
}

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n) {
            result.insert(result.begin(), 1, --n%26+'A');
            n /= 26;
        }
        return result;
    }
};


