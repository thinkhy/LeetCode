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


class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int m = a.size();
        int n = b.size();

        int tmp = 0;

        while (m+n >0){
            tmp += m>0? a[--m] - '0': 0;
            tmp += n>0? b[--n] - '0': 0;

            result.insert(result.begin(), ('0' + tmp%2));
            tmp /= 2;
        }
        return (tmp == 0)? result: "1"+result;
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



