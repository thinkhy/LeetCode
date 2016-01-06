/**********************************************************************
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

**********************************************************************/
#include <stdio.h>
#include <stdlib.h>

int nthSuperUglyNumber(int n, int* primes, int primesSize) {

   1 1*2 2*2 1*7  2*2*2 13*1 2*7  2^4 1*19 2*13 2^2*7 2^5 2*19 7^2
   1 2   4   7    8     13   14   16  19   26   28    32
   1 2  3   4    5      6    7     8  9    10   11    12

}

int main() {
   // int primes[] = {1,2,4,7,8,13,14,16,19,26,28,32};
   int primes[] = {2,7,13,19};
   int n = 12;
   int result = nthSuperUglyNumber(n, primes,  sizeof(primes)/sizeof(primes[0]));
    
}


