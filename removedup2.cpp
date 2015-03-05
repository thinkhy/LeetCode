#include <iostream>
#include <string>
#include <map>
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
    int removeDuplicates(int A[], int n) {
       if(n == 0 || n == 1) return n; 
       int counter = 0;
       int i = 0;
       while(i < n) {
           int cnt = 1;
           int cur = A[i];
           for(i=i+1;i<n&&A[i] == cur;i++,cnt++);
           for(int j = 0; j < min(2,cnt); j++)
               A[counter++] = cur;
       }
       return counter;
    }
};

int main() {
    //int a[] = {0,1,1,2,2,2,3,3,3,4,4,4,4,5,5,5,5,5};
    int a[] = {-3,-1};
    Solution s;
    int len = s.removeDuplicates(a, sizeof(a)/sizeof(a[0]));
    for(int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
