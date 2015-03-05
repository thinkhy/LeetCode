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
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;
        else if (divisor == 0)
            return numeric_limits<int>::max();
        else if (divisor == 1)
            return dividend;
        else if (divisor == 2)
            return dividend >> 1;

        bool is_negnum = false; 
        if (dividend < 0 && divisor > 0) { 
            is_negnum = true;
            dividend = -dividend;
        } else if(dividend > 0 && divisor < 0) {
            is_negnum = true;
            divisor = -divisor;
        }else if(dividend < 0 && divisor < 0) {
            is_negnum = false;
            dividend = -dividend;
            divisor = -divisor;
        }

        int left = dividend;
        int quotient = 0;

        while (left >= divisor) {
            left = left - divisor;    
            quotient++;
        }

        return is_negnum ? -quotient : quotient;
    }
};

int main() {
    Solution s;
    int dividend = 1;
    int divisor = -1;
    cout << s.divide(dividend, divisor) << endl;

    dividend = -1;
    divisor = 1;
    cout << s.divide(dividend, divisor) << endl;

    dividend = -1;
    divisor = -1;
    cout << s.divide(dividend, divisor) << endl;

    dividend = 100;
    divisor = 0;
    cout << s.divide(dividend, divisor) << endl;

    dividend = 0;
    divisor = 2;
    cout << s.divide(dividend, divisor) << endl;

    dividend = 0;
    divisor = 0;
    cout << s.divide(dividend, divisor) << endl;

    dividend = 2147483647;
    divisor = 1;
    cout << s.divide(dividend, divisor) << endl;

    dividend = 2147483647;
    divisor = 2;
    cout << s.divide(dividend, divisor) << endl;

    return 0;
}
