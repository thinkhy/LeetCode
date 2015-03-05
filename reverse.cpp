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
    int reverse(int x) {
       int s = 0;
       while(x) {
           s = s*10 + x%10;
           x/=10;
       }

       return s;
    }
};


int main() {
    Solution s;
    int num;

    num = 123;
    cout << s.reverse(num) << endl;

    num = -321;
    cout << s.reverse(num) << endl;

    num = 0;
    cout << s.reverse(num) << endl;

    num = 10;
    cout << s.reverse(num) << endl;

    return 0;
}
