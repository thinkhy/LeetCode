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
    void merge(int A[], int m, int B[], int n) {
        int i, j, k, h;    
        i = j = 0;
        int lena = m;
        int lenb = n;

        while(i < lena + lenb) {
            if(i >= m) {
                A[i++] = B[j++];
            }
            else {
                while(i<m && A[i] <= B[j]) { 
                    i = i + 1;
                }
                if(i == m) continue;
                 
                for(k = 0; j+k < n && B[j+k] < A[i]; k++);
                    
                for(h = m-1; h >= i; h--) A[h+k] = A[h];
                for(h = 0; h < k; h++) A[i++] = B[j++];
                    
                m = m + k;
            }
        }
    }
};

void print(int a[], int n) {
    for(int i = 0; i < n; i++)  
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    Solution s;
    int a[100];
    int k = 0;
    for(int i = 0; i < 100; i+=2) {
        a[k++] = i;
    }

    int b[100];
    k = 0;
    for(int i = 1; i < 100; i+=2) {
        b[k++] = i;
    }


    int m,n;
    /*
    m = 0;
    n = 0;
    s.merge(a,m,b,n);
    print(a,m+n);

    m = 0;
    n = 1;
    s.merge(a,m,b,n);
    print(a,m+n);

    m = 1;
    n = 0;
    s.merge(a,m,b,n);
    print(a,m+n);
    */

    m = 1;
    n = 1;
    s.merge(a,m,b,n);
    print(a,m+n);

    m = 1;
    n = 0;
    k=0;
    for(int i = 0; i < 100; i+=2) {
        a[k++] = i;
    }
    k=0;
    for(int i = 1; i < 100; i+=2) {
        b[k++] = i;
    }
    s.merge(a,m,b,n);
    print(a,m+n);

    return 0;
}


