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

#define DE(a) cout << #a << ": " << a << endl;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void do_work(string &result, int factor[], int n, int k) {
        if(k == 0) return;

        int cnt = 0;
        while(factor[cnt+1] <= k) cnt++; 
        int multiple = k%factor[cnt] ? k/factor[cnt]+1 : k/factor[cnt];
        k = k%factor[cnt];

        int start = n - 1 - cnt;

        //DE(start);
        //DE(multiple);
        if(multiple > 1) {
            char tmp = result[start];
            result[start] =  result[start + multiple - 1];
            // remove result[start]
            result.erase(result.begin() + start + multiple - 1);
            // insert original value before result.begin()
            result.insert(result.begin() + start+1, tmp);
        }
        //DE(result);
        if(k == 0) 
            reverse(result.begin()+start+1, result.end());
        else 
            do_work(result, factor, n, k);
    }
    
    string getPermutation(int n, int k) {
        // cout << s.getPermutation(9, 217778) << endl;
        int q = k; 
        int cnt = 1;

        int factor[10];
        factor[0] = 1;
        for(int i = 1; i <= 10; i++) {
            factor[i] = factor[i-1]*i;
        }
        string result;
        result.resize(n);
        for(int i = 0; i < n; i++) {
           result[i] = i+'1'; 
        }

        do_work(result, factor, n, k);

        return result;
    }


};
int main() {
    Solution s;

//    cout << s.getPermutation(3,0) << endl;
//   cout << s.getPermutation(3,1) << endl;
    //cout << s.getPermutation(3,2) << endl;
//    cout << s.getPermutation(3,3) << endl;
    //cout << s.getPermutation(3,4) << endl;
//   cout << s.getPermutation(3,5) << endl;
//    cout << s.getPermutation(3,6) << endl;
    cout << s.getPermutation(4, 9) << endl;
    cout << s.getPermutation(9, 7778) << endl;
    cout << s.getPermutation(9, 217778) << endl;
    cout << endl;
}


