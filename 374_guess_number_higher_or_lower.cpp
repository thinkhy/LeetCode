#include <cstdio>
using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int m) {
  if (m == 6)
	return 0;
  if (m < 6)
 	return -1;
  if (m > 6)
 	return 1;
}

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int h = n;
        while (l < h) {
            int m = l + (h-l)/2;
            int ans = guess(m);
            if (ans == 0)
               return m;
            else if (ans == -1) 
               l = m+1;
            else if (ans == 1)
               h = m-1;
        }
        return l;
    }
};


int main() {
   Solution s;
   printf("%d\n", s.guessNumber(10));
   return 0;
}


