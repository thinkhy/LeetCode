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

      // divide by 27 and insert the character regarding to modulus into the result.
      q = n;
      while(q > 26) {
          q /= 27;
          r %= 27;
          res.insert(res.begin(), 1, 'A'+r);
      }
      res.insert(res.begin(), 1, 'A'+q-1);
    }
};

int main() {
    Solution slt;
    DE(slt.convertToTitle(1));
    DE(slt.convertToTitle(2));
    DE(slt.convertToTitle(3));
    DE(slt.convertToTitle(26));
    DE(slt.convertToTitle(27));
    DE(slt.convertToTitle(28));

    return 0;
}

