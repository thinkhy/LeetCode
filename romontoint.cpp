#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
using namespace std;

/*******************************************************************
 *
    Roman Numerals, as used today, are based on seven symbols:[1]
    Symbol	Value
    I	1
    V	5
    X	10
    L	50
    C	100
    D	500
    M	1,000
    Numbers are formed by combining symbols and adding the values. So II is two ones, i.e. 2, and XIII is a ten and three ones, i.e. 13. There is no zero in this system, so 207, for example, is CCVII, using the symbols for two hundreds, a five and two ones. 1066 is MLXVI, one thousand, fifty and ten, a five and a one.
    Symbols are placed from left to right in order of value, starting with the largest. However, in a few specific cases,[2] to avoid four characters being repeated in succession (such as IIII or XXXX) these can be reduced using subtractive notation as follows:[3][4]
    the numeral I can be placed before V and X to make 4 units (IV) and 9 units (IX respectively)
    X can be placed before L and C to make 40 (XL) and 90 (XC respectively)
    C can be placed before D and M to make 400 (CD) and 900 (CM) according to the same pattern[5]
    An example using the above rules would be 1904: this is composed of 1 (one thousand), 9 (nine hundreds), 0 (zero tens), and 4 (four units). To write the Roman numeral, each of the non-zero digits should be treated separately. Thus 1,000 = M, 900 = CM, and 4 = IV. Therefore, 1904 is MCMIV
 *********************************************************************/

class Solution {
public:
    /*
    Roman Numerals, as used today, are based on seven symbols:[1]
    Symbol	Value
    I	1
    V	5
    X	10
    L	50
    C	100
    D	500
    M	1,000
    */
    inline int symbol2int(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
    /*
     * the numeral I can be placed before V and X to make 4 units (IV) and 9 units (IX respectively)
     * X can be placed before L and C to make 40 (XL) and 90 (XC respectively)
     * C can be placed before D and M to make 400 (CD) and 900 (CM) according to the same pattern[5]
     */
    int romanToInt(string s) {
        int result = 0;
        int len = s.size();
        int i = 0;
        for(; i < len-1; i++) {
            if((s[i] == 'I'&&(s[i+1] == 'V' || s[i+1] == 'X') ) 
               || (s[i] == 'X'&&(s[i+1] == 'L' || s[i+1] == 'C') ) 
               || (s[i] == 'C'&&(s[i+1] == 'D' || s[i+1] == 'M') ) 
              ) {
                result += symbol2int(s[i+1]) - symbol2int(s[i]);
                i++;
            }
            else
                result += symbol2int(s[i]);
        }
        // left the last symbol
        if(i == len-1)
                result += symbol2int(s[i]);

        return result;
    }
};

int main() {
    Solution s; 
    string str = "DCXXI";
    cout << s.romanToInt(str) << endl;  
    str = "MCMIV";
    cout << s.romanToInt(str) << endl;  
    str = "MCMLIV";
    cout << s.romanToInt(str) << endl;  
    str = "MCMXC";
    cout << s.romanToInt(str) << endl;  
    str = "MMXIV";
    cout << s.romanToInt(str) << endl;  

    return 0;
}
