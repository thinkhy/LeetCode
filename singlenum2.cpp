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
    int singleNumber(int A[], int n) {
        map<int, int> nmap;        
        for(int i = 0; i < n; i++) {
            if(nmap.find(A[i]) == nmap.end())
                nmap[A[i]] = 1;
            else
                nmap[A[i]]++;
        }

        for(map<int, int>::iterator it=nmap.begin(); it != nmap.end(); it++) 
            if(it->second == 1)
                return it->first;

        return 0;
    }
};

int main() {
    Solution s;
    int a[] = {1, 2, 1, 3, 3};
    cout << s.singleNumber(a, sizeof(a)/sizeof(int)) << endl;

    return 0;
}
