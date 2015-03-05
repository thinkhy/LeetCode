#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {

            if (x < 0)
                return false;

            int n = 1;                
            int s = 1;

            while(x/n>=10) {
                n *= 10;
                s++;
            }

            n=1;

            while(s>1 && x%((int)pow(10, 1))==x/(int(pow(10, s-1)))) {
                x = x%(int(pow(10, s-1)));
                x = x/10;
                s=s-2;
            }

            return s <= 1;
        }
};

int main() {
    Solution s;
    cout << s.isPalindrome(0) << endl;
    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(1234321) << endl;
    cout << s.isPalindrome(12343210) << endl;
    
    return 0;
}


