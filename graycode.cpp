#include <iostream>
#include <string>
#include <map>
#include <set>
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
    vector<int> grayCode(int n) {
        vector<int> re;
        unordered_set<int> numbers;
        if(n==0) {
            re.push_back(0);
            return re;
        }

        int num = 0;
        int flippos = 0;
        int i;

        do {
            numbers.insert(num);
            re.push_back(num);

            for(i = 0; i < n; i++) {
                int next = (1<<i)^num;
                if(numbers.find(next) == numbers.end()) {
                    num = next;
                    break;
                }
            }
        } while(i<n);
         
            
        return re;
    }
};
;

void print(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++)  
        cout << vec[i] << " ";
    cout << endl;
}

int main() {
    Solution s;
    for(int i = 0; i < 10; i++) {
        vector<int> re = s.grayCode(i);
        print(re);
    }
    return 0;
}


