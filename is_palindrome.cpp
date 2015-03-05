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
 * Rotate List Total 
 *
 *  Total Accepted: 30954 Total Submissions: 141501
 *
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * For example,
 *  "A man, a plan, a canal: Panama" is a palindrome.
 *  "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 * For the purpose of this problem, we define empty string as valid palindrome.
 *
 ************************************************************************************************************************/

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        do {
            while(i<j) {
                if ((s[i] >= 'a' && s[i] <= 'z')
                        || (s[i] >= '0' && s[i] <= '9'))
                    break;
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    s[i] = 'a'+s[i]-'A';
                    break;
                }
                i++;
            }

            while(i<j) {
                if ((s[j] >= 'a' && s[j] <= 'z')
                        || (s[j] >= '0' && s[j] <= '9'))
                    break;
                if (s[j] >= 'A' && s[j] <= 'Z') {
                    s[j] = 'a'+s[j]-'A';
                    break;
                }
                j--;
            }
            
            if(i>=j) break;

            if(s[i] != s[j])
                return false;

        } while(++i < --j);
        
        return true;;
    }
};

int main() {
    Solution slt;
    DE(slt.isPalindrome("A man, a plan, a canal: Panama"));
    DE(slt.isPalindrome("race a car"));
    DE(slt.isPalindrome("1a2"));

    return 0;
}






