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
#include <cmath>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

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
    int findMin(vector<int> &num) {
        if(num.empty()) return 0;

        int i;
        for(i = 1; i<num.size() && num[i-1]<num[i]; i++);
        
        return i==num.size() ? num[0] : num[i];
    }
};

int main() {
    Solution s;

    vector<int> nums(7);
    nums[0] = 4;
    nums[1] = 5;
    nums[2] = 6;
    nums[3] = 7;
    nums[4] = 0;
    nums[5] = 1;
    nums[6] = 2;

    cout << s.findMin(nums) << endl;

    return 0;
}



