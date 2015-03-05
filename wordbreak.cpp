#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

class Solution {
public:
    bool findstring(string s, 
                   unordered_set<string> &dict,
                   unordered_set<string> &failures) {

       unordered_set<string>::iterator it = dict.end();
       bool ret = false;

       if(s.empty())
           return true;

       for (it = dict.begin(); it != dict.end(); it++) {
          string curstr = *it;  
          if (curstr.size() > 0 && s.substr(0, curstr.size()) == curstr) {
            unordered_set<string> words(dict); 
            words.erase(curstr);
            string left = s.substr(curstr.size());

            //cout << left << endl;
            //cout << words.size() << endl;

            if (failures.find(left) != failures.end())
                continue;

            ret = findstring(left, dict, failures);
            if (ret) 
                break;     
            else
                failures.insert(left);
            // else
          }
       }

       return ret;
    }
    bool wordBreak(string s, unordered_set<string> &dict) {
        unordered_set<string> failures;
        return findstring(s, dict, failures);
    }
};

int main() {
    string s = "leetcode";
    unordered_set<string> dict;
    dict.insert("leet");
    dict.insert("code");

    Solution slt;
    cout << slt.wordBreak(s, dict) << endl;


   s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
   dict.clear();
   dict.insert("a");
   dict.insert("aa");
   dict.insert("aaa");
   dict.insert("aaaa");
   dict.insert("aaaaa");
   dict.insert("aaaaaa");
   dict.insert("aaaaaaa");
   dict.insert("aaaaaaaa");
   dict.insert("aaaaaaaaa");
   dict.insert("aaaaaaaaaa");
   cout << slt.wordBreak(s, dict) << endl;

}

