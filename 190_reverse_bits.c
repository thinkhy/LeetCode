#include <stdio.h>
#include <stdlib.h>

/***************************************************
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
 *
 * Follow up:
 * If this function is called many times, how would you optimize it?
 *
 * Related problem: Reverse Integer
 *  *
 *
 * Refer to: http://stackoverflow.com/questions/47981/how-do-you-set-clear-and-toggle-a-single-bit-in-c-c
 * 
 **************************************************************************************************************/

#define SETBIT(n,k)  n |= 1 << (k)
#define CLRBIT(n,k)  n &= ~(1 << (k))
#define TGLBIT(n,k)  n ^= ~(1 << (k))
#define CHKBIT(n,k)  ((n)>>(k)) & 1
#define CHGBIT(n,k,x)  n ^= (-(x) ^ (n)) & (1 << (k))

uint32_t reverseBits(uint32_t n) {
   int i;
   for (i = 0; i < 16; i++) {
      uint32_t tmp = CHKBIT(n, i);
      CHGBIT(n, i, CHKBIT(n, 31-i)); 
      CHGBIT(n, 31-i, tmp); 
   }
   return n;    
}

int main() {
  uint32_t n = 1;
  printf("%u\n", reverseBits(0)); 
  printf("%u\n", reverseBits(n)); 
  printf("%u\n", reverseBits(43261596)); 
  printf("%u\n", reverseBits(964176192)); 
  return 0;
}



