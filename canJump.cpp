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
    bool canJump(int a[], int n) {
       int i = 0; 
       int maxpos = 0;
        
       while(i < n-1) {     
           maxpos = max(maxpos, a[i]+i);
           if(maxpos <= i)
               break;
           i++;
       }
        
       return maxpos >= (n-1);
    }
};


int main() {
    Solution s;
    
    int a[] = {2, 3, 1, 1, 4};
    cout << s.canJump(a, sizeof(a)/sizeof(a[0])) << endl;

    int b[] = {3, 2, 1, 0, 4};
    cout << s.canJump(b, sizeof(b)/sizeof(b[0])) << endl;

    int c[] = {2,5,0,0};
    cout << s.canJump(c, sizeof(c)/sizeof(c[0])) << endl;

    return 0;
}






