#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
class Solution {
public:
    void find_ip(string& s,
                 vector<string>& re,
                 string digits,
                 int ordinal,
                 int cur_pos) {

        if(ordinal == 5 && cur_pos == s.size()) {
            re.push_back(digits);
            return;
        }
        else if(ordinal >= 5 || cur_pos >= s.size()) 
            return;

        int i = cur_pos;
        for(int i = cur_pos; i < s.size() && i-cur_pos<3; i++) {
            int num = atoi(s.substr(cur_pos, i-cur_pos+1).c_str());
            if(num < 0 || num > 255) break;

            string tmp = digits;
            tmp += s.substr(cur_pos, i-cur_pos+1);  
            if(ordinal != 4)
                tmp.push_back('.');

            find_ip(s, re, tmp, ordinal+1, i+1);

            if(num == 0) break;
        }

        return;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> re;    
        string digits;
        find_ip(s, re, digits, 1, 0);
        return re;
    }
};

int main() {
    Solution slt;
    string str = "010010";

    vector<string> re = slt.restoreIpAddresses(str);
    for(int i = 0; i < re.size(); i++)
        cout << re[i] << " ";
     
    cout << endl;
    return 0;
}



