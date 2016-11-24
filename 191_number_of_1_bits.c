#include <stdio.h>
#include <string.h>

/***************************************************************************************************
 *
 * Write a function that takes an unsigned integer and returns the number of ’1'
 * bits it has (also known as the Hamming weight).
 *
 * For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011,
 * so the function should return 3.
 *
 ***************************************************************************************************/
int hammingWeight(uint32_t n) {
	int res=0;
	while(n) {
		if (n&0x01) res++;
		n >>= 1;
	}
	return res;
}

int hammingWeight_recursive(uint32_t n) {
	if (n == 0) return 0;
	return n%2 + hammingWeight(n/2);
}

int main() {
  
}
