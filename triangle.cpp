#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
#include <iterator>
#include <cstdio>
using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty()||triangle[0].empty()) 
            return 0;        
        if(triangle.size() == 1) 
            return triangle[0][0];        

        vector<int> path = triangle.back();
        int len = triangle.size();

        for(int i = len-2; i >= 0; i--) {
            for(int j = 0; j < triangle[i].size(); j++) {
                int cur = triangle[i][j];
                path[j] = min(path[j], path[j+1]) + cur;
            }

        }

        return path[0];
    }
};

int main() {
    Solution s;
    vector< vector<int>  > triangle;
    vector<int> tmp;

    tmp.resize(1);
    tmp[0] = -1;
    triangle.push_back(tmp);

    tmp.resize(2);
    tmp[0] = 3; tmp[1] = 2;
    triangle.push_back(tmp);

    tmp.resize(3);
    tmp[0] = -3; tmp[1] = 1; tmp[2] = -1;
    triangle.push_back(tmp);
    /*
      -1 
       3  2
      -3  1  -1
     */


    cout << s.minimumTotal(triangle) << endl;
    
    return 0;
}



