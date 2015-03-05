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
using namespace std;

class Solution {
public:
    /**
     * 
     **/
    int climbStairs(int n) {
        vector<int> s(n+1);        
        s[0] = 1;
        s[1] = 1;
        for(int i = 2; i <= n; i++)
            s[i] = s[i-2]+s[i-1];

        return s[n];
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(0) << endl;
    cout << s.climbStairs(1) << endl;
    cout << s.climbStairs(2) << endl;
    cout << s.climbStairs(3) << endl;
    cout << s.climbStairs(4) << endl;
    cout << s.climbStairs(5) << endl;
    cout << s.climbStairs(6) << endl;

    return 0;
}


