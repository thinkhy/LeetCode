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
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/


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


class Solution {
public:  
    bool is_palindrome(const string& s) {
        int start = 0;
        int end = s.size()-1;
        while(start < end) {
            if(s[start++] != s[end--]) 
                return false;
        }

        return true;
    }

    vector<vector<string>> partition(string s) {
       int len = s.size();
       if(len == 0)
           return vector<vector<string>>();

       bool isPalin[len][len];
       for(int i = len-1; i >= 0; i++) {
           for(int j = 0; j +i < len; j++) {
               if(s[i] == s[i+j] && (j<2 || isPalin[i+1][j-2])) 
                   isPalin[i][j] = true;
               else 
                   isPalin[i][j] = false;
           }
       }

       vector<vector<string>> trans[s.size()+1];
       vector<string> tmp;
       trans[0].push_back(tmp);
       tmp.push_back(s.substr(0,1));
       trans[1].push_back(tmp);

       for(int i = 1; i < s.size(); i++) {
           for(int j = i; j >= 0; j--) {
                string cur = s.substr(j, i-j+1);
                //if(is_palindrome(cur)) {
                DE(isPalin[i][j]);
                if(isPalin[i][j]) {
                   vector<vector<string> > cur_trans = trans[j]; 
                   for(int k = 0; k < cur_trans.size(); k++) {
                        cur_trans[k].push_back(cur);
                   }
                   trans[i+1].insert(trans[i+1].end(), 
                           cur_trans.begin(), cur_trans.end());
                }
           }
       }
        
       return trans[s.size()];
    }

};

int main() {
    Solution s;
    string str = "aab";

    vector<vector<string> > re;
    re = s.partition(str); 
    DE(re.size());

    for(int i = 0; i < re.size(); i++) {
        for(int j = 0; j < re[i].size(); j++)
            cout << re[i][j] << " ";
        cout << endl;
    }

    return 0;
}



