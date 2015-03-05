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

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int len = num.size();
        int i, j;
        for(i = len-1; i > 0 && num[i] <= num[i-1]; i--); 
        if(i != 0) {
            for(j = i; j < len && num[j] > num[i-1]; j++);
            swap(num[i-1], num[j-1]);
        }

        reverse(num.begin()+i, num.end());

        return;
    }

};

int main() {
    Solution s;
    vector<int> num;

    num.resize(3);
    num[0] = 3; num[1] = 2; num[2] = 1;
    s.nextPermutation(num);
    for(int i = 0; i < num.size(); i++) 
            cout << num[i] << " ";
    cout << endl;

    return 0;
}


