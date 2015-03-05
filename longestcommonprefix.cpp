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
    string longestCommonPrefix(vector<string> &strs) {
       string common; 
       if(strs.empty()) 
           return common;

       common = strs[0];
       for(int i = 1; !common.empty() && i < strs.size(); i++) {
           int pos = 0;
           for(; strs[i][pos] == common[pos]; pos++);
           common = common.substr(0, pos); 
       }

       return common;
    }
};


int main() {
    Solution s;
    
    vector<string> strs;
    strs.push_back("abcefes");
    strs.push_back("a");
    strs.push_back("abce");
    strs.push_back("abce");
     
    cout << s.longestCommonPrefix(strs);

    return 0;
}






