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
 * 4Sum
 * Given an array S of n integers, are there elements a, b, c, 
 * and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 *
 * For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 * 
 *     A solution set is:
 *     (-1,  0, 0, 1)
 *     (-2, -1, 1, 2)
 *     (-2,  0, 0, 2)
 *
 **/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num, int begin, int end, int target) {
        vector<vector<int> > results;
        if(num.empty())
            return results;

        DE(begin);
        DE(end);
        DE(target);
        int len = num.size();

        for(int first = begin; first < end-2; first++) {
            if(first > begin && num[first] == num[first-1])
                continue;

            int second = first+1;
            int third = len-1;
            while(second < third) {
                int sum = num[first] + num[second] + num[third];
                if(sum == target) {
                    vector<int> triplets(3);
                    triplets[0] = num[first];
                    triplets[1] = num[second];
                    triplets[2] = num[third];
                    results.push_back(triplets);

                    while(second<third&&num[second++] == num[second]);
                    while(second<third&&num[third--] == num[third]);
                }
                else if(sum > target) 
                    third--;
                else
                    second++;
            }
        }
        return results;
    }

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > re;
        if(num.size() < 4) return re;

        sort(num.begin(), num.end());
        int last = INT_MAX;
        int len = num.size();
        for(int i = 0; i < len-3; i++) {
            if(i > 0 && num[i] == last)
                continue;
            last = num[i];
            vector<vector<int> > triplets;
            DE(target);
            DE(num[0]);
            DE(num[1]);
            DE(num[2]);
            triplets = threeSum(num, i+1, len, target-num[i]);
            for(int j = 0; j < triplets.size(); j++) {
                vector<int> quadruplet(4);
                quadruplet[0] = last;
                quadruplet[1] = triplets[j][0];
                quadruplet[2] = triplets[j][1];
                quadruplet[3] = triplets[j][2];
                re.push_back(quadruplet);
            }
        }

        return re;
    }
};

int main() {
    Solution s;
    vector<int> num;
    num.resize(6);
    num[0] = 1;
    num[1] = 0;
    num[2] = -1;
    num[3] = 0;
    num[4] = -2;
    num[5] = 2;

    int target = 0;
    vector<vector<int> > re;
    re = s.fourSum(num, target);
    for(int i = 0; i < re.size(); i++) {
        for(int j = 0; j < 4; j++) {
            cout << re[i][j] << " ";
        }
        cout << endl;
    }

    num.resize(4);
    num[0] = 0;
    num[1] = 0;
    num[2] = 0;
    num[3] = 0;
    cout << "========================================" << endl;

    target = 0;
    re = s.fourSum(num, target);
    for(int i = 0; i < re.size(); i++) {
        for(int j = 0; j < 4; j++) {
            cout << re[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


