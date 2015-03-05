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
       if (n == 0 || n == 1) return n;
       int i = 1;
       int len = n;
       int pre = A[0];

       while(i < len) {     
           if(pre == A[i])  {
               len--;
               for(int j = i+1; j < n; j++) {
                   A[j-1]=A[j];
               }
           }
           else
               pre = A[i++];

       }

       return len;
    }
};

int main() {
    int a[] = {1,1,2,2,2,3};
    Solution s;
    int len = s.removeDuplicates(a, 3);
    for(int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
