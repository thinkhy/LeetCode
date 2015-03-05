#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
#include <iterator>
#include <cstdio>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*
 * ZigZag string
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
class Solution {
public:
    string convert(string s, int nRows) {
        string re;
        int len = s.size();
        re.resize(len);
        int cnt = 0;

        //string lastline;

        for(int i = 0, pos = 0; cnt<len&&i*2*(nRows-1)<len; i++) {
            //int end = cur + nRows - 1;
            // convert the first row
            re[cnt++] = s[pos]; 
             pos += nRows==1 ? 1 : 2*(nRows-1);

            // convert the last row
            //if(end < len)
            //    lastline += s[end];
        }

        // convert the middle row
        for(int i = 1; i < nRows-1; i++) {
           for(int pos=i, j=1; pos < len; j++) {
               re[cnt++] = s[pos]; 
               if(j&0x1) {
                 pos += (nRows-1-i)*2;
               }
               else {
                 pos += i*2;
               }
           }
        }

        // convert the last row
        for(int i = 0; cnt<len&&(2*i+1)*(nRows-1)<len; i++) {
            int end = (2*i+1)*(nRows-1);

            re[cnt++] = s[end]; 
        }

        return re;
    }
};


int main() {
    Solution s;
    string str="PAYPALISHIRING";
    cout << s.convert(str, 3) << endl;
    str="AB";
    cout << s.convert(str, 1) << endl;

    return 0;
}








