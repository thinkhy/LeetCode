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
    void onePassStd(int a[], int n) {
        int low,mid,high;          
        low  = 0;
        mid  = 1;
        high = 2;

        int i = 0;
        int iLow = -1;
        int iHigh = n;


        while(i < iHigh) {
            if(a[i] <= low) 
                swap(a[i++], a[++iLow]);
            else if(a[i] >= high)
                swap(a[i], a[--iHigh]);
            else
                i++;
        }

    }

    void onePass(int a[], int n) {
        int zeros, ones, twos;
        int i,pos;
        zeros = ones = twos = -1;

        for(i = 0; i < n; i++) {
            if(a[i] == 0) {
                a[++twos]  = 2;
                a[++ones]  = 1;
                a[++zeros] = 0;
            }
            else if(a[i] == 1) {
                a[++twos]  = 2;
                a[++ones]  = 1;
            }
            else
                a[++twos] = 2;
        }
    }

    void twoPass(int a[], int n) {
        int zeros, ones, twos;
        int i,pos;
        zeros = ones = twos = 0;

        for(i = 0; i < n; i++) {
            if(a[i] == 0)
                zeros++;
            else if(a[i] == 1)
                ones++;
            else
                twos++;
        }

        pos=0;
        for(i = 0; i < zeros; i++) a[pos++] = 0;
        for(i = 0; i < ones; i++) a[pos++] = 1;
        for(i = 0; i < twos; i++) a[pos++] = 2;
    }

    void sortColors(int a[], int n) {
        //twoPass(a,n);    
        //onePass(a,n);    
        onePassStd(a,n);
    }
};

int main() {
    Solution s;
    int a[] = {2,1,0,0,1,2,0,1};
    s.sortColors(a, sizeof(a)/sizeof(*a));

    for(int i = 0; i < sizeof(a)/sizeof(*a); i++) { 
        cout << a[i] << " ";
    }

    return 0;
}


