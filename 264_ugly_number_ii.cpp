/****************************************************************************************************
 * 264#
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
 * For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 * 
 * Note that 1 is typically treated as an ugly number.
 *  
 * Solution refer to: http://stackoverflow.com/questions/4600048/nth-ugly-number
 *                    http://stackoverflow.com/questions/5505894/tricky-google-interview-question  
 * 
 **************************************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_SIZE   3*1000000
#define DE(x)      do { printf("%s:%d\n", #x, (x)); } while(0);   
#define swap(a, b) do { (a)=(a)^(b);(b)=(a)^(b);(a)=(b)^(a); } while(0)

/*
void heap_insert(int *heap, int num) {
  return;
}

int nthUglyNumber(int n) {
    int *heap= (int*)malloc(MAX_SIZE);
    
    static int primes[] = {2, 3, 5};
    heap[0] = 1;
    int cnt = 1;
    int i, num, result;

    while (cnt < n) {
      for (i = 0; i < 3; i++) {
         num = cnt * primes[i];
         heap_insert(heap, num);
      }
      swap(heap[0], heap[3*cnt]);
      cnt++;
    }

    num = heap[0]; 
    free(heap);
    return num;
}
*/

/* 
   Dijkstra derives an eloquent solution in "A Discipline of Programming".
   He attributes the problem to Hamming. Here is my implementation of Dijkstra’s solution.
*/
class Solution {
public:
int nthUglyNumber(int n) {
    std::vector<int> v(n);
    v[0] = 1;

    int i2 = 0;             // Index for 2
    int i3 = 0;             // Index for 5
    int i5 = 0;             // Index for 5

    int x2 = 2 * v[i2];     // Next two candidates
    int x3 = 3 * v[i3];     // Next two candidates
    int x5 = 5 * v[i5];

    for (int i = 1; i != n; ++i)
    {
        int m = min(x2, min(x3, x5));
        // std::cout << m << " ";
        v[i] = m;

        if (x2 == m)
        {
            ++i2;
            x2 = 2 * v[i2];
        }
        if (x3 == m)
        {
            ++i3;
            x3 = 3 * v[i3];
        }
        if (x5 == m)
        {
            ++i5;
            x5 = 5 * v[i5];
        }
    }

    return v[n-1];
}
};

int main() {
   Solution s;
   int n = 10;  
   DE(s.nthUglyNumber(n));
   DE(s.nthUglyNumber(1));
}


