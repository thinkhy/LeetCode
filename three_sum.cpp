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

/**
 * 3Sum
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 *  
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * For example, given array S = {-1 0 1 2 -1 -4},
 *  
 * A solution set is:
 *     (-1, 0, 1)
 *     (-1, -1, 2)
 *
 **/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > results;
        if(num.empty())
            return results;

        sort(num.begin(), num.end());

        int len = num.size();
        vector<int> last_triplets;
        for(int i = 0; i < len-2 && num[i] <= 0; i++) {
            if(i>0 && num[i] == num[i-1])
                continue;

            for(int j = i+1; j < len-1; j++) {
                if(num[i]+num[j]>0)
                    break;

                if(last_triplets.size()>0
                        && last_triplets[0] == num[i] 
                        && last_triplets[1] == num[j])
                    continue;

                for(int k = j+1; k < len; k++) {
                    if(last_triplets.size() > 0 
                       && last_triplets[0] == num[i]
                       && last_triplets[1] == num[j]
                       && last_triplets[2] == num[k])
                        continue;

                    int sum = num[i]+num[j]+num[k];
                    if(sum == 0) {
                        vector<int> triplets(3);
                        triplets[0]=num[i];
                        triplets[1]=num[j];
                        triplets[2]=num[k];
                        results.push_back(triplets);

                        last_triplets = triplets;
                    }
                    else if(sum > 0)
                        break;
                }
            }
        }

        return results;
    }
};

int main() {
    Solution s;
    vector<int> num;
    vector<vector<int>> result;
     
    num.resize(6);
    num[0] = 3;
    num[1] = 0;
    num[2] = -2;
    num[3] = -1;
    num[4] = 1;
    num[5] = 2;
        
    result.clear();
    result = s.threeSum(num);
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < 3; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    num.clear();
    num.assign(4, 0);
    result = s.threeSum(num);
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < 3; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    int a[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    num.clear();
    num.assign(a, a+sizeof(a)/sizeof(*a));
    result = s.threeSum(num);
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < 3; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
        
    return 0;
}



