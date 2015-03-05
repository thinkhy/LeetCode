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
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;
   
class Solution {
public:

     void dfs(unordered_map<char, string>& phone_pad, 
              string& digits, 
              vector<string>& results, 
              int pos,
              string& s) {
              if(pos==digits.size()) {
                  results.push_back(s);
                  return;
              }
              if(digits.empty()) return;

              char cur = digits[pos];
              for(int i = 0; i < phone_pad[cur].size(); i++) {
                   s[pos] = phone_pad[cur][i];
                   dfs(phone_pad, digits, results, pos+1, s);
              }

              return;
          }

     vector<string> letterCombinations(string digits) {
        unordered_map<char, string> phone_pad; //build hash table 
        phone_pad['2']= "abc";
        phone_pad['3']= "def";
        phone_pad['4']= "ghi";
        phone_pad['5']= "jkl";
        phone_pad['6']= "mno";
        phone_pad['7']= "pqrs";
        phone_pad['8']= "tuv";
        phone_pad['9']= "wxyz";

        vector<string> results;
        string s;
        s.resize(digits.size());
        dfs(phone_pad, digits, results, 0, s);

        return results;
    }
};

int main() {
    Solution s;
    vector<string> re;
    re = s.letterCombinations("");
    for(int i = 0; i < re.size(); i++) {
        cout << re[i] << " ";
    }
    cout << endl;

    return 0;
}


