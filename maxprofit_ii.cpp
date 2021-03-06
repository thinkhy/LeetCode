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
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if(len <= 1) return 0;

        int income = 0;

        for (int i = 1; i < len; i++) {
            if(prices[i-1] < prices[i]) 
                income += prices[i] - prices[i-1];
        }

        return income;
    }
};


int main() {
    Solution s;
    vector<int> prices;
    prices.push_back(5);
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(0);
    prices.push_back(1);
    
    cout << s.maxProfit(prices) << endl;

    return 0;
}




