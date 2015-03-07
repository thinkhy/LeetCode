#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Single Number II Total Accepted: 42084 Total Submissions: 121816 My Submissions Question Solution 
 * Given an array of integers, every element appears three times except for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

/*
int singleNumber(int a[], int n) {
	int i; 
	int ones, twos, threes;
	ones = twos = threes = 0;
	for(i = 0; i < n; i++) {
		twos |= ones & a[i]; 
		ones ^= a[i];	
		threes = ones & twos;
		ones ^= threes;
		twos ^= threes;
	}

	return ones;
}
*/

int singleNumber(int a[], int n) {
	int i;
	int x;
	int x0 = ~0, x1 = 0, x2 = 0, t;
	for (i = 0; i < n; i++) {
		x = a[i];
		t = x2;	
		x2 = (x1 & x) | (x2 & ~x);
		x1 = (x0 & x) | (x1 & ~x);
		x0 = (t  & x) | (x0 & ~x);
	}
		
	return x1;
}

int main() {

    int a[] = {1,1, 2, 1,3, 3, 3};
    printf("%d\n", singleNumber(a, sizeof(a)/sizeof(*a)));
    return 0;
}


