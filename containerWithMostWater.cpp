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

/*********************************************************
 *
 * Given n non-negative integers a1, a2, ..., an, 
 * where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints 
 * of line i is at (i, ai) and (i, 0). Find two lines,
 * which together with x-axis forms a container, such 
 * that the container contains the most water.
 * Note: You may not slant the container.
 *
 *********************************************************/
class Solution {
public:
    int maxArea(vector<int> &height) {
        int len = height.size();
        if(len <= 1) return 0;

        int maxwater = 0;
        for(int i = 0; i < len; i++) {
            for(int j = i+1; j < len; j++) {
                int water = min(height[j], height[i])*(j-i);
                if(water > maxwater)
                    maxwater = water;
            }
        }

        return maxwater;
    }
};


int main() {
    Solution s; 
    vector<int> height;
    height.resize(2);
    height[0] = 2;
    height[1] = 2;
    cout << s.maxArea(height) << endl;

    height.resize(3);
    height[0] = 3;
    height[1] = 2;
    height[2] = 4;
    cout << s.maxArea(height) << endl;

    height.resize(4);
    height[0] = 1;
    height[1] = 2;
    height[2] = 3;
    height[3] = 4;
    cout << s.maxArea(height) << endl;

    return 0;
}



