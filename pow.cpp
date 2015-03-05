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

/*
 * Implement pow(x, n).
 */


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
    double pow(double x, int n) {
        const double ZERO=0.0000001;
        double re = 1;
        if(fabs(x-0)<ZERO) return 0;
        if(n<0) {
            x = 1/x;
            n = -n;
        }
        double tbx[32];
        tbx[0] = x;
        for(int i = 1; i < 32; i++)
            tbx[i] = tbx[i-1]*tbx[i-1];

        for(int i = 0; i < 31; i++) {
            if((0x1<<i)&n)
                re *= tbx[i];
        }

        return re;
    }
};

int main() {
    Solution s;
    cout << s.pow(2.0, 3) << endl;
    cout << s.pow(0.00001, 2147483647) << endl;
    cout << s.pow(34.00515, -3) << endl;
    cout << s.pow(-13.62608, 3) << endl;

    return 0;
}



