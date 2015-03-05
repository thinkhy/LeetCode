#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
public class Solution {
    public int trap(int[] A) {
        int secHight = 0;
        int left = 0;
        int right = A.length - 1;
        int area = 0;
        while (left < right) {
            if (A[left] < A[right]) {
                secHight = Math.max(A[left], secHight);
                area += secHight - A[left];
                left++;
            } else {
                secHight = Math.max(A[right], secHight);
                area += secHight - A[right];
                right--;
            }
        }
        return area;
    }
}

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

