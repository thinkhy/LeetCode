#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
       int carry; 
       int len = digits.size();
       if(len == 0) return vector<int>();

       int sum = digits[len-1]+1;
       digits[len-1] = sum%10;
       carry = sum/10;

       int i;
       for(i = len-2; i >= 0&&carry; i--) { 
           sum = digits[i]+carry;
           digits[i] = sum%10;
           carry = sum/10;
       }

       if(carry)
           digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main() {
    Solution s;
    vector<int> num;
    vector<int> r;
    int n;

    num.clear();
    n = 3;
    num.resize(n);
    for(int i = 0; i < n; i++)
        num[i] = i+1;

    r = s.plusOne(num);
    cout << "======" << endl;
    for(int i = 0; i < r.size(); i++) {
            cout << r[i];
    }

    cout << endl;

    num.clear();
    n = 9;
    num.resize(n);
    for(int i = 0; i < n; i++) {
        num[i] = 9;
        cout << num[i];
    }
    cout << endl;

    r = s.plusOne(num);
    cout << "======" << endl;
    for(int i = 0; i < r.size(); i++) {
            cout << r[i];
    }
    cout << endl;

    return 0;
}


