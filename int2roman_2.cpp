#include <iostream>
#include <sstream>
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

/*****************************************************************************
 * The numbers 1 to 10 can be expressed in Roman numerals as follows:
 *   I, II, III, IV, V, VI, VII, VIII, IX, X.
 *
 *   Symbol	Value
 *       I	1
 *       V	5
 *       X	10
 *       L	50
 *       C	100
 *       D	500
 *       M	1,000
 *
 *  Numbers are formed by combining symbols and adding the values. So II is two ones, i.e. 2, and XIII is a ten and three ones, i.e. 13. There is no zero in this system, so 207, for example, is CCVII, using the symbols for two hundreds, a five and two ones. 1066 is MLXVI, one thousand, fifty and ten, a five and a one.
 *
 *  Symbols are placed from left to right in order of value, starting with the largest. However, in a few specific cases,[2] to avoid four characters being repeated in succession (such as IIII or XXXX) these can be reduced using subtractive notation as follows:[3][4]
 *     the numeral I can be placed before V and X to make 4 units (IV) and 9 units (IX respectively)
 *     X can be placed before L and C to make 40 (XL) and 90 (XC respectively)
 *     C can be placed before D and M to make 400 (CD) and 900 (CM) according to the same pattern[5]
 *
 *  An example using the above rules would be 1904: this is composed of 1 (one thousand), 9 (nine hundreds), 0 (zero tens), and 4 (four units). To write the Roman numeral, each of the non-zero digits should be treated separately. Thus 1,000 = M, 900 = CM, and 4 = IV. Therefore, 1904 is MCMIV.
 *
 *  Below are some examples of the modern use of Roman Numerals.
 *    1954 as MCMLIV (Trailer for the movie The Last Time I Saw Paris)[6]
 *    1990 as MCMXC (The title of musical project Enigma's debut album MCMXC a.D., named after the year of its release.)
 *    2014 as MMXIV - the year of the games of the XXII (22nd) Olympic Winter Games (in Sochi)
 *
 ****************************************************************************/
class Solution {
public:
    string intToRoman(int num) {
       string ss; 
       int values[13]=      {1,  4,   5,  9,   10,  40,  50, 90,
                           100,  400,  500,900,  1000};
       const char* symbols[13] = {"I", "IV", "V", "IX", "X", "XL","L","XC",
                           "C", "CD", "D", "CM", "M"};
       int i=12;
       while(num!=0&&i>=0) {
           if(num >= values[i]) {
               for(int j = 0; j < num/values[i]; j++)
                   ss<<symbols[i];
               num%=values[i];
           }
           else
               i--;
       }

       return ss.str();
    }
};

int main() {
    Solution s;
    // I
    cout << s.intToRoman(1) << endl;
    //II
    cout << s.intToRoman(2) << endl;
    //V
    cout << s.intToRoman(5) << endl;
    //XIII
    cout << s.intToRoman(13) << endl;
    //CCVII
    cout << s.intToRoman(207) << endl;
    //MCMIV
    cout << s.intToRoman(1904) << endl;
    //MLXVI
    cout << s.intToRoman(1066) << endl;
    //MCMLIV
    cout << s.intToRoman(1954) << endl;
    //MCMXC
    cout << s.intToRoman(1990) << endl;
    //MMXIV
    cout << s.intToRoman(2014) << endl;
    /*
    for(int i = 1; i < 3999; i++) {
        cout << s.intToRoman(i) << endl;
    }
    */

    return 0;
}


