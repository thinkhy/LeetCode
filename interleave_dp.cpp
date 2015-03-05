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
                    
            int l1 = s1.size();
            int l2 = s2.size();
            int l3 = s3.size();

            if (l1 + l2 != l3)
                return false;

            vector< vector<bool> > s(l1+1);

            for(int i = 0; i <= l1; i++) {
                s[i].resize(l2+1);
                for(int j = 0; j <= l2; j++)
                {
                   s[i][j] = false;
                }
            }

            s[0][0] = true;
            cout << s1 << endl;
            cout << s2 << endl;
            cout << s3 << endl;

            for(int i = 0; i <= l1; i++) {
                for(int j = 0; j <= l2; j++) {
                    if ((i-1 >= 0 && s[i-1][j] && s3[i+j-1] == s1[i-1])
                        ||  (j-1>= 0 && s[i][j-1] && s3[i+j-1] == s2[j-1]))
                        s[i][j] = true;

                }
            }

            return s[l1][l2];
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

    s1 = "aabcc";
    s2 = "dbbca";
    s3 = "aadbbcbcac";
    cout << s.isInterleave(s1,s2,s3) << endl;

    s1 = "bccbcccacabbbcab";
    s2 = "cabbabacbc";
    s3 = "abbbbbcccccbcaacacbabbccab";
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s.isInterleave(s1,s2,s3) << endl;

    s1 = "";
    s2 = "";
    s3 = "";
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s.isInterleave(s1,s2,s3) << endl;
}


