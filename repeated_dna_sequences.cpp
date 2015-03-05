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
 * Repeated DNA Sequences  
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
 * 
 * Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
 * 
 * For example,
 *   Given s = "AAAAACCCCCAAAAACCCCCAAAAAGGGTTT",
 *   Return:
 *     ["AAAAACCCCC", "CCCCCAAAAA"].
 *
 ************************************************************************************************************************/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    }
};

int main() {
    Solution slt;

    string s1 = "AAAAACCCCCAAAAACCCCCAAAAAGGGTTT";
    vector<string> res;
    res = slt.findRepeatedDnaSequences(s1);
    cout << "s: " << s1 << endl;
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    cout << endl;

    return 0;
}






