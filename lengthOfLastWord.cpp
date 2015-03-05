#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstring>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(s == NULL) return 0;

        int len = strlen(s);
        if(len == 0) return 0;

        int r = 0;
        int i;
        for(i = len-1; i>=0&&s[i]==' '; i--);
        for(; i>=0&&s[i]!=' '; i--,r++);

        return r;
    }
};


int main() {
    Solution s;
    cout << s.lengthOfLastWord(NULL) << endl;
    cout << s.lengthOfLastWord("") << endl;
    cout << s.lengthOfLastWord("  ") << endl;
    cout << s.lengthOfLastWord("  Hello  ") << endl;
    cout << s.lengthOfLastWord("Hello World") << endl;

    return 0;
}



