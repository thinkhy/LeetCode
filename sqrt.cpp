#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*******************************************************************************************************************
 *
 * Maximum Product Subarray
 *
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 *
 ************************************************************************************************************************/
class Solution {
public:
    int find_squqre_root(int x, int start, int end) {
        
        //cout << x << ": " << start << ": " << end << endl;
        if(start >= end) {
            while(end * end > x)
                end -= 1;

            return end;
        }
         
        int mid = (start + end) / 2;
        int square = mid * mid;
        if(square<0)         // square overflow
            return find_squqre_root(x, start, mid-1);
        else if(square == x) // find it
            return mid;
        else {
            if(square > x)   
                end = mid-1;
            else if(square < x) 
                start = mid+1;
            return find_squqre_root(x, start, end);
        }
    }

    int sqrt(int x) {
        if(x == 0 || x == 1) return x;

        int end = 1;
        int digit = 1;
        int tmp = x;
        while(tmp/=10) digit++;
        if(digit == 1)
            end = x;
        else {
            for(int i = 1; i <= (digit+1)/2; i++)
                end *= 10;
        }
        return find_squqre_root(x, 1, end);
    }
};

int main() {
    Solution s;
        
    int x;
    x = 2147483647;
    DE(s.sqrt(x));
    x = 2147395599;
    DE(s.sqrt(x));
    x = 25;
    DE(s.sqrt(x));
    x = 64;
    DE(s.sqrt(x));
    x = 225;
    DE(s.sqrt(x));
    x = 4;
    DE(s.sqrt(x));
        
    return 0;
}






