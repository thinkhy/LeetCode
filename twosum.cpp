#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
       vector<int> result(2);
       map<int, vector<int> > num2pos;
       int len = numbers.size();

       map<int, vector<int> >::iterator it = num2pos.end(); 
       for (int i = 0; i < len; i++) {
           int curNum = numbers[i];

           if (num2pos.find(curNum) != num2pos.end()) {
              num2pos[curNum].push_back(i+1);  
           }
           else {
              vector<int> tmp(1);
              tmp[0] = i+1;
              num2pos.insert(make_pair(numbers[i], tmp));
           }
       }

       it = num2pos.begin();
       for(int i = 0; i <= len/2; it++, i++) {
           int second = target - it->first;

           if (it->first == second && (it->second).size() > 1) {
               result[0] = (it->second)[0];
               result[1] = (it->second)[1];
           }
           else if (num2pos.find(second) != num2pos.end()) {
               result[0] = (it->second)[0];
               result[1] = num2pos[second][0];
               break;
           }

       }

       if (result[0] > result[1]) 
           swap(result[0], result[1]);

       return result;
    }
};

int main() {
    Solution s;
    vector<int> numbers;
    int target;
    target = 6;
    numbers.resize(4); 
    numbers[0] = -11;
    numbers[1] = 4;
    numbers[2] = 17;
    numbers[3] = 2;

    vector<int> result = s.twoSum(numbers, target);
    cout << result[0] << "  " << result[1] << endl;

    numbers.clear();
    target = 0;
    numbers.resize(4); 
    numbers[0] = 0;
    numbers[1] = 4;
    numbers[2] = 17;
    numbers[3] = 0;

    result = s.twoSum(numbers, target);
    cout << result[0] << "  " << result[1] << endl;

    return 0;
}

