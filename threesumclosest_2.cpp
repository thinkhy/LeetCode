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

        int mindist = numeric_limits<int>::max();
        bool found = false;
        for(int i = 0; (!found)&&(i < len - 2); i++) {
            int j = i + 1;
            int k = len-1;
            while(j<k) {
                int sum = num[i] + num[j] + num[k];
                // cout << sum << endl;
                if(sum == target) {
                    result = sum;
                    found = true;
                    break;
                }

                if(abs(sum - target) < mindist) {
                    result = sum;    
                    mindist = abs(sum - target);    
                }
                
                sum > target ? k-- : j++;
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








