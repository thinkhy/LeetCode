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
        bool isneg;
        if ((dividend < 0) ^ (divisor < 0))  
            isneg = true;
        else
            isneg = false;
        
        if (dividend == 0)
            return 0;
        else if (divisor == 0) 
            return numeric_limits<int>::max();


        int result = 0; 
        int digit = 0;
        long long divid = dividend;
        long long divis = divisor;
        divid = divid > 0 ? divid : -divid; 
        divis =  divis > 0 ? divis : -divis;

        // find the left-most divisor
        while (divis <= divid) {
            divis <<= 1;
            digit++;
            //cout << "divid: " << divid << "divis: " << divis << endl;
            //cout << "digit: " << digit << endl;
        }

        // perform binary division
        while(divid >= divisor && digit > 0) {
            divis >>= 1;
            digit--;
            //cout << "digit: " << digit << endl;

            if (divid >= divis) {
                divid = divid - divis;
                result = result + (1<<digit);
            }
        }

        return isneg ? -result : result;
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

    dividend = -1010369383;
    divisor =  -2147483648;
    cout << s.divide(dividend, divisor) << endl;

    return 0;
}
