    #include <iostream>
    #include <string>
    #include <map>
    #include <vector>
    #include <algorithm>
    #include <utility>

    using namespace std;
    class Solution {
    public:
        int trap(int A[], int n) {
           int  w = 0;
           int left, right, mid, pos;
           bool lflag, rflag;
           lflag = rflag = false;

           left = 0;
           while(left + 1< n) {
               while(left+1<n && A[left] == A[left+1]) 
                   left++;


               right=mid = pos = left;
               while(pos+1<n && A[pos] > A[pos+1]) {
                 pos++;
                 if(!lflag) lflag=true;
               }
               if (!lflag) {
                   left++;
                   continue;
               }
               right = mid = pos;

               int i;
               for(i = left+1; i<n&&A[i]<A[left]; i++);
               if (A[i] >= A[left])  {
                   right = i;
                   rflag = true;
               }
               else {
                   while(right+1<n&&A[right] <= A[right+1]) {
                       right++;
                       if(!rflag) rflag=true;
                   }
               }

               if(lflag && rflag) {
                   int ceil = min(A[left], A[right]);
                   for(int i = left+1; i < right; i++) { 
                       if (ceil - A[i] > 0)
                           w += (ceil -  A[i]);
                   }
               }
               //cout << left << " " << right << " " << w << endl;

               left=right;
               lflag = rflag = false;
           }

           return w;
        }
    };

    int main() {
        Solution s;
        int *a=new int[12];
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
        cout << "020" << endl;

        a[0] = 0;
        a[1] = 2;
        a[2] = 0;
        cout <<s.trap(a, 3) << endl;
    }
