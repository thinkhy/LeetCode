#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
                    
            cout << "Begin" << endl;
            if (s1+s2 == s3 || s2+s1 == s3 || s1.size() + s2.size() != s3.size())
                return false;

            int pos1, pos2, pos3;
            pos1 = pos2 = pos3 = 0;

            vector<int> trace(s3.size());
            for(int i = 0; i < trace.size(); i++)
                trace[i] = -1;

            int which = 0;
            int last = 0;

            while(pos1 >= 0 && pos2 >= 0 && pos3 >= 0 && pos3 < s3.size()) {

                /*cout << which << " pos1: " << pos1 << " " << s1[pos1] 
                      << " pos2: " << pos2 << " " << s2[pos2]
                       << " pos3: " << pos3 << " " << s3[pos3]  << "trace[pos3]: " << trace[pos3] << endl;
                       */

                if (which == 0) {
                   if (trace[pos3] == 0) {
                       pos1--;
                       pos3--;
                       which = !which;
                   }
                   else if (pos1 < s1.size() && s1[pos1] == s3[pos3]) {
                       trace[pos3] = which;
                       pos1++;
                       pos3++;
                       last = which;
                       if (pos1 == s1.size())
                           which = !which;
                   }
                   else {
                       if (last != which) {
                           pos3--;
                           trace[pos3] ? pos2-- : pos1--;
                       }
                       // which = (trace[pos3]+1)%2;
                       which = !which;
                   }
                }
                else {
                   if (trace[pos3] == 1) {
                       pos2--;
                       pos3--;
                       which = !which;
                   }
                   else if (pos2 < s2.size() && s2[pos2] == s3[pos3]) {
                       trace[pos3] = which;
                       pos2++;
                       pos3++;
                       last = which;
                       if (pos2 == s2.size())
                           which = !which;
                   }
                   else {
                       if (last != which) {
                           pos3--;
                           trace[pos3] ? pos2-- : pos1--;
                       }
                       // which = (trace[pos3]+1)%2;
                       which = !which;
                   }
                }
            }

            return pos1 == s1.size() && pos2 == s2.size() && pos3 == s3.size();
        }
};

int main() {
    Solution s;

    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s.isInterleave(s1,s2,s3) << endl;

    s1 = "bccbcccacabbbcab";
    s2 = "cabbabacbc";
    s3 = "abbbbbcccccbcaacacbabbccab";
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s.isInterleave(s1,s2,s3) << endl;
}


