/********************************************************************************************
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
 * For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 * 
 * Note that 1 is typically treated as an ugly number.
 *  
 ********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE  3*1000000
#define swap(a, b) do { (a)=(a)^(b);(b)=(a)^(b);(a)=(b)^(a); } while(0)

void heap_insert(int *heap, int num) {
  return;
}

int nthUglyNumber(int n) {
    int *heap= (int*)malloc(MAX_SIZE);
    
    static int primes[] = { 2, 3, 5};
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

int main() {
  
}
