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
#include <cmath>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

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

I think my solution is more efficient than yours.

    class Solution {
    public:
        string addBinary(string a, string b) {
            string re;

            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            int pos = 0;
            int carry = 0;
            while(pos < a.size() && pos < b.size()) {  
                int cur  = carry + a[pos] - '0' + b[pos] - '0';
                carry = cur/2;
                re.insert(re.begin(), '0'+cur%2);
                pos++;
            }
            string remain;
            if(pos == a.size())
                remain = b;
            else
                remain = a;
            for(int i = pos; pos < remain.size(); pos++) {
                int cur  = carry + remain[pos] - '0';
                carry = cur/2;
                re.insert(re.begin(), '0'+(cur%2));
            }
            if(carry)
                re.insert(re.begin(), '1');

            return re;
        }
    };

int main() {
    Solution s;

    string a, b;
    a="11001000011101111111010011101001111111110000110101000";
    b="1010110011100010000110100011001101110001111001001010001100000100011111011011111";
    cout << s.addBinary(a, b) << endl;
    a="11";
    b="1";
    cout << s.addBinary(a, b) << endl;

    a="1010";
    b="1011";
    cout << s.addBinary(a, b) << endl;

    return 0;
}



