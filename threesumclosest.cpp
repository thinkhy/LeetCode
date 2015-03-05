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
    int threeSumClosest(vector<int> &num, int target) {
        int result;
        int len = num.size();

        sort(num.begin(), num.end());

        int last = numeric_limits<int>::max();
        bool found = false;
        for(int i = 0; (!found)&&(i < len - 2); i++) {
            for(int j = i+1; (!found)&&(j < len - 1); j++) {
                for(int k = j+1; (!found)&&(k < len); k++) {
                    int sum = num[i] + num[j] + num[k];
                    //cout << i << " " << j << " " << k << endl;
                    //cout << num[i] << " " << num[j] << " " << num[k] << endl;
                    //cout << sum << endl;
                    if(abs(sum - target) < abs(last-target)) {
                        result = sum;    
                        last = sum;    
                        //found = true;
                    }
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution s;
    vector<int> num;
    int target;

    num.push_back(-1);
    num.push_back(2);
    num.push_back(1);
    num.push_back(-4);

    target = 1;
    cout << s.threeSumClosest(num, target) << endl;


    return 0;
}








