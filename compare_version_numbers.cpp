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
 * Compare Version Numbers
 *  
 * Compare two version numbers version1 and version1.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 * 
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 * 
 * Here is an example of version numbers ordering:
 * 
 * 0.1 < 1.1 < 1.2 < 13.37
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 *
 ************************************************************************************************************************/

class Solution {
public:
    /*********************************************************
     *
     * if version1 > version2 
     *    return 1
     * if version1 < version2 
     *    return -1
     * otherwise 
     *    return 0.
     *
     *********************************************************/
    int compareVersion(string version1, string version2) {
        int version = 0;

        // the version number will be divided into two parted seperated by dot
        // let's say we have two number, first-level revision and second-level revision
        int first_level1, first_level2;
        int second_level1, second_level2;
        first_level1 = first_level2 = 0;
        second_level1 = second_level2 = 0;
                
        // calculate for the first-level revision iteratively
        int i = 0,j = 0;
        while(i < version1.size() || j < version2.size()) {
            first_level1 = first_level2 = 0; 

            for(; i < version1.size()&&version1[i] != '.'; i++) 
                first_level1 = first_level1*10 + (version1[i]-'0');
            for(; j < version2.size()&&version2[j] != '.'; j++) 
                first_level2 = first_level2*10 + (version2[j]-'0');

            if(first_level1 != first_level2)
                return first_level1 > first_level2 ? 1 : -1;

            // pass over '.'
            if(i < version1.size()) i++;
            if(j < version2.size()) j++;
        }

        return 0;
    }
};

int main() {
    Solution slt;

    DE(slt.compareVersion("0",   "0"));
    DE(slt.compareVersion("0.1", "1.1"));
    DE(slt.compareVersion("1.1", "1.2"));
    DE(slt.compareVersion("1.2", "1.10"));
    DE(slt.compareVersion("1.2", "1.3"));
    DE(slt.compareVersion("1.3", "13.37"));
    DE(slt.compareVersion("1.2", "1.19"));
    DE(slt.compareVersion("1.2", "2.19"));
    DE(slt.compareVersion("10.6.5", "10.6"));
    DE(slt.compareVersion("1.0", "1"));
    DE(slt.compareVersion("1", "1.1"));


    return 0;
}

