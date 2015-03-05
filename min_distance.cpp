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
#include <cmath>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

    a) Insert a character
    b) Delete a character
    c) Replace a character

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();    
        int len2 = word2.size();    
        if(len1 == 0 || len2 == 0) return len1^len2;

        vector<int> last(len2+1);
        vector<int> cur(len2+1);
        for(int i = 0; i <= len2; i++)
            last[i] = i;

        for(int i = 1; i <= len1; i++) {
            cur[0] = i;
            for(int j = 1; j <= len2; j++) {
                    cur[j]=min(last[j-1]+(word2[j-1]==word1[i-1]?0:1), 
                                min(last[j]+1, 
                                    cur[j-1]+1
                                   )
                               );
            }
            last = cur;
        }

        return cur[len2];
    }
};

int main() {
    Solution s;
     
    string word1 = "a";
    string word2 = "b";
     
    cout << s.minDistance(word1, word2) << endl;
     
    return 0;
}





