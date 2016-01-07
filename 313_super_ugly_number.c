/**********************************************************************
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 10^6, 0 < primes[i] < 1000.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
   1 1*2 2*2 1*7  2*2*2 13*1 2*7  2^4 1*19 2*13 2^2*7 2^5 2*19 7^2
   1 2   4   7    8     13   14   16  19   26   28    32
   1 2   3   4    5      6    7   8    9   10   11    12
*/
#define MAXNUM 1000000L
#define MIN(x,y)  ((x)>(y)?(y):(x))

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    int i,j;
    int *indices = (int*)malloc(primesSize*4);
    memset(indices, 0, primesSize*4);

    int *num = (int*)malloc(MAXNUM*4);
    int cnt = 1;
    num[0] = 1;
    int cur = num[0];

    while(cnt < n) {
        cur = num[indices[0]]*primes[0];
        for(i = 1; i < primesSize; i++) {
            cur = MIN(cur, num[indices[i]] * primes[i]);
        }

        for(j = 0; j < primesSize; j++) {
            if (cur == num[indices[j]] * primes[j])
                indices[j]++;
        }
        num[cnt++] = cur;
        // printf("cnt: %d cur: %d\n", cnt, cur);
    }

    free(indices);
    free(num);

    return cur;
}

int main() {
   // int primes[] = {1,2,4,7,8,13,14,16,19,26,28,32};
   int primes[] = {2,7,13,19};
   int n = 12;
   int result = nthSuperUglyNumber(n, primes,  sizeof(primes)/sizeof(primes[0]));

   printf("result: %d\n", result);

}


