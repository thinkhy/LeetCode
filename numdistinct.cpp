#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
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
    int numDistinct(string s, string t) {
        int cnt = 0;
        int len1 = s.size();
        int len2 = t.size();
        vector<int> lastlevel(s.size()+1, 0);
        vector<int> curlevel(s.size()+1);
        vector<int> lastpath(s.size()+1, 1);
        vector<int> curpath(s.size()+1);
        curpath[0] = 0;

        for(int i = 1; i <= len2; i++) {
            for(int j = 1; j <= len1; j++) {
                if(t[i-1] == s[j-1]) {
                    int tmp = lastlevel[j-1]+1;
                    if(tmp == curlevel[j-1]) {
                        curlevel[j] = tmp;
                        curpath[j] = curpath[j-1] + lastpath[j-1];
                    }
                    else if(tmp > curlevel[j-1]) {
                        curlevel[j] = tmp;
                        curpath[j] = lastpath[j-1];
                    }
                    else {
                        curlevel[j] = curlevel[j-1];
                        curpath[j] = curpath[j-1];
                    }
                }
                else {
                    curlevel[j] = curlevel[j-1];
                    curpath[j] = curpath[j-1];
                }
                /*
            DE(i);
            DE(j);
            DE(t[i-1]); DE(s[j-1]);
            DE(lastlevel[j-1]);
            DE(curlevel[j]);
            DE(curlevel[j-1]);
            DE(lastpath[j-1]);
            DE(curpath[j]);
            */
            }

            lastlevel = curlevel;
            lastpath = curpath;
        }

        return curpath[s.size()];
    }
};

int main() {
    Solution sol;

    string s = "rabbbit";
    string t = "rabbit";
    cout << sol.numDistinct(s, t) << endl;

    s = "ACEE";
    t = "AE";
    cout << sol.numDistinct(s, t) << endl;

    t = "r";
    s = "rabbitr";
    cout << sol.numDistinct(s, t) << endl;
    t = "b";
    s = "a";
    cout << sol.numDistinct(s, t) << endl;
}



