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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
       int size = gas.size();

       int total = 0, tank = 0, start = 0;;

       for(int i = 0; i < size; i++) {
           tank = tank + gas[i] - cost[i];
           if (tank < 0) {
               start = i+1;
               total += tank;
               tank = 0;
           }
       }
       if (tank > 0)
           total += tank;
       
       return total >= 0 ? start : -1;
    }
};

int main() {
    Solution s;
    vector<int > gas;
    vector<int > cost;
    int num = 3;
    gas.push_back(2);
    cost.push_back(2);

    gas.push_back(2);
    cost.push_back(3);

    gas.push_back(3);
    cost.push_back(3);

    gas.push_back(4);
    cost.push_back(4);

    cout << s.canCompleteCircuit(gas, cost) << endl;

    return 0;
}



