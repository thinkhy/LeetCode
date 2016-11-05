/****************************************************************
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

 Do not allocate extra space for another array, you must do this in place with constant memory.

 For example,
 Given input array nums = [1,1,2],

 Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

 Subscribe to see which companies asked this question
 ****************************************************************/
#include <stdio.h>

int removeDuplicates(int *nums, int numsSize) {
   if (nums == NULL || numsSize <= 0)
   	return 0;
   int *p1, *p2;
   for ( p1 = nums, p2 = p1+1; p2 != nums + numsSize; ) {
       if (*p1 == *p2) 
       	     p2++;
       else {	
          *(++p1) = *(p2++);
       }
   }
   return p1-nums+1;
}

int main() {
  int nums[] = {1, 1, 2};
  int size = sizeof(nums)/sizeof(nums[0]);
  int ss = removeDuplicates(nums, size);
  printf("Size: %d\nNums: ", ss); 
  for (int i = 0; i < ss; i++) {
     printf("%d\t", nums[i]); 
  }
  printf("\n"); 
}
