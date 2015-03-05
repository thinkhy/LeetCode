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
    int removeElement(int a[], int n, int elem) {
        if(n==0) return 0;

        sort(a, a+n);

        int i, firstpos;
        for(i=0; i<n; i++) {
            if(a[i] == elem) 
                break;
        }
        if(i==n) 
            return n;
        else
            firstpos=i;

        int len = 0;
        while(i<n&&a[i]==elem) { 
            i++;
        }
        len = i-firstpos;

        if (len>0) {
            int start = firstpos;
            while(start+len<n) {
                a[start]=a[start+len];
                start++;
            }
        }

        return n-len;
    }
};

int main() {
    Solution s;
    int a[] = {1,3,3,3,2,1,3,2,1,33,2};
    int len;
    cout <<  sizeof(a)/sizeof(*a) << endl;
    len=s.removeElement(a, sizeof(a)/sizeof(*a), 3);
    for(int i =0; i<len; i++)  
        cout << a[i] << "  ";
    cout << endl;
    int b[]={};
    len=s.removeElement(b, sizeof(b)/sizeof(*b), 3);
    for(int i =0; i<len; i++)  
        cout <<  b[i] << "  ";
    cout << endl;

    return 0;
}


