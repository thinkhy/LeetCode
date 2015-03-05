#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/********************************************************************************************************************
 *
 * Best Time to Buy and Sell Stock III  
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 *
 ********************************************************************************************************************/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;

        int result = 0;
        int len = prices.size();

        vector<int> historyProfit;
        vector<int> futureProfit;
        historyProfit.assign(len, 0);
        futureProfit.assign(len, 0);
         
        int low = 0;
        low = prices[0];
        for(int i = 1; i < len; i++) { 
            low = min(low, prices[i]);
            historyProfit[i] = max(historyProfit[i-1], prices[i]-low);
        }

        int high = prices[len-1];
        for(int i = len-1; i>0; i--) {
            high = max(high, prices[i]);
            futureProfit[i] = max(futureProfit[i-1], high-prices[i]);
            result = max(result, historyProfit[i]+futureProfit[i]);
        }

        return result;
    }
};

int main() {
    Solution s;

    vector<int> prices;
    prices.resize(10);
    prices[0]=1;
    prices[1]=2;
    prices[2]=3;
    prices[3]=4;
    prices[4]=5;
    prices[5]=4;
    prices[6]=3;
    prices[7]=4;
    prices[8]=6;
    prices[9]=5;

    cout << s.maxProfit(prices) << endl;
    vector<int> dumm = vector<int>();
    cout << s.maxProfit(dumm) << endl;

    return 0;
}



