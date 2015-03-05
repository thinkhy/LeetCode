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

       vector<int> travel(size);  // left gas between different gas stations
       for(int i = 0; i < size; i++) {
           travel[i] = 0;
       }

       for(int i = 1; i <= size; i++) { 
         for(int j = 0; j < size; j++) {
            int last = (j+i-1)%size;
            if(travel[j] >= 0)
                travel[j] = travel[j] + gas[last] - cost[last];
            // cout << "travel[" << j << "][" << next << "]: " << travel[j][next] << endl;
         }
       }

       for(int i = 0; i < size; i++) { 
            if (travel[i] >= 0)
                return i;
       }

       return -1;
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
    cost.push_back(2);

    gas.push_back(3);
    cost.push_back(3);

    gas.push_back(4);
    cost.push_back(4);

    cout << s.canCompleteCircuit(gas, cost) << endl;


    return 0;
}



