#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
class Solution {
public:
    int trap(int a[], int n) {
       int s = 0; 
       int e = n-1;
       int maxWater = 0;
       int curWater = 0;
       int level, lastLevel;
       lastLevel = 0;
       while(s < e) {
           // calculate current water
           if(min(a[s], a[e]) > lastLevel) {
               lastLevel = level;
               level = min(a[s], a[e]);
               for(int i = s+1; i < e; i++) {
                    if(a[i] < level && a[i] >= lastLevel)
                        curWater += level - a[i];
                    else if(a[i] < lastLevel) 
                        curWater += level - lastLevel;
               }
               if(curWater > maxWater)
                   maxWater = curWater;
           }

           if(a[s] > a[e])
               e--;
           else if(a[s] < a[e])
               s++;
           else {
               e--;
               s++;
           }
       }

       return maxWater;
    }
};

int main() {
    Solution s;
    int *a=new int[12];
    a[0] = 2;
    a[1] = 0;
    a[2] = 2;
    cout <<s.trap(a, 3) << endl;

    /*
    a[0]  = 0;
    a[1]  = 1;
    a[2]  = 0;
    a[3]  = 2;
    a[4]  = 1;
    a[5]  = 0;
    a[6]  = 1;
    a[7]  = 3;
    a[8]  = 2;
    a[9]  = 1;
    a[10] = 2;
    a[11] = 1;

    cout <<s.trap(a, 12) << endl;
    cout <<s.trap(a, 0) << endl;

    a[0]=1; a[1]=1;
    cout <<s.trap(a, 2) << endl;

    a[0]=1; a[1]=1;a[2]=2;
    cout <<s.trap(a, 3) << endl;

    a[0]=1; a[1]=1;a[2]=2;a[3]=1;
    cout <<s.trap(a, 4) << endl;

    a[0]=1; a[1]=2;a[2]=3;a[3]=4;
    cout <<s.trap(a, 4) << endl;

    a[3]=1; a[2]=2;a[1]=3;a[0]=4;
    cout <<s.trap(a, 4) << endl;

    a[6]=100;a[5]=2;a[4]=2;a[3]=3; a[2]=2;a[1]=1;a[0]=2;
    cout <<s.trap(a, 7) << endl;

    a[4] = 5; a[3]=1; a[2]=2;a[1]=1;a[0]=5;
    cout <<s.trap(a, 5) << endl;

    a[0] = 2;
    a[1] = 0;
    a[2] = 2;
    cout <<s.trap(a, 3) << endl;
    */
}
