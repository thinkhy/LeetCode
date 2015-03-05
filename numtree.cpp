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
    int numTrees(int n) {
        vector<int> num(n+1);
        num[0] = 1;
        for(int i = 1; i <= n; i++) {
            num[i] = 0;
            for(int j = 0; j < (i>>1); j++)
                num[i] += num[j]*num[i-j-1];
            num[i] <<= 1;
            if(i&1) {
                num[i] += num[i>>1]*num[i>>1];;
            }
        }

        return num[n];
    }
};

int main() {
    Solution s;
    cout << s.numTrees(0) << endl;
    cout << s.numTrees(1) << endl;
    cout << s.numTrees(2) << endl;
    cout << s.numTrees(3) << endl;
    cout << s.numTrees(4) << endl;

    return 0;
}


