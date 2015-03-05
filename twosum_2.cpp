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
       int len = numbers.size();

       vector<int>::iterator itBegin = numbers.begin();
       vector<int>::iterator itFound = numbers.end();
       for (int i = 0; i < len-1; i++) {
           int first = numbers[i];
           int second = target - first; 
           
           itFound = find(itBegin+i+1, numbers.end(), second);
           if(itFound != numbers.end()) {
               result[0] = i+1;
               result[1] = itFound - itBegin + 1;
               break;
           }
       }
        
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

