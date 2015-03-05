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

        int bottom = prices[0];
        int max = 0;

        for (int i = 1; i < len; i++) {
            int gap = prices[i] - bottom;
            if (gap < 0)
                bottom = prices[i];
            else if (gap > max)  
                max = gap;
        }

        return max;
    }
};


int main() {
    Solution s;
    vector<int> prices;
    prices.push_back(5);
    prices.push_back(4);
    prices.push_back(0);
    prices.push_back(4);
    prices.push_back(1);
    prices.push_back(6);
    
    cout << s.maxProfit(prices) << endl;

    return 0;
}




