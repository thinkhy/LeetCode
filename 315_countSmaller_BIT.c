#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**************************************************************************

 You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

 Example:

 Given nums = [5, 2, 6, 1]

 To the right of 5 there are 2 smaller elements (2 and 1).
 To the right of 2 there is only 1 smaller element (1).
 To the right of 6 there is 1 smaller element (1).
 To the right of 1 there is 0 smaller element.
 Return the array [2, 1, 1, 0].

 **************************************************************************/
#define MAX_SIZE  120000

static int val[MAX_SIZE];

void MakePositive(int nums[], int numsSize) {
    int i, j;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] < 0) {
            int acc = -nums[i];
            for(j = 0; j < numsSize; j++) {
                nums[j] += acc;
            }
        }
    }
}

int Get(int index) {
   int result = 0;
   while(index != 0) {
       result += val[index];
       index = index - (index&-index);
   }

   return result;
}

void Add(int index, int value) {
   while(index < MAX_SIZE) {
       val[index] += value;
       index = index + (index&-index);
   }
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int *results;
    int i,cnt, value;

    if (numsSize <= 0) return NULL;

    results = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    memset(val, 0, sizeof(val));

    MakePositive(nums, numsSize);

    for(i = numsSize-1; i >= 0; i--) {
        results[i] = Get(nums[i]);
        Add(nums[i]+1, 1);
    }

    return results;
}



int main() {
   // int nums[] = {5, 2, 6, 1};
   // int nums[] = {2,0,1};
   int nums[] = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};

   int i;

   int resultSize;
   int *results = countSmaller(nums, sizeof(nums)/sizeof(nums[0]), &resultSize);
   for(i = 0; i < resultSize; i++) {
       printf("%d ",results[i]);
   }
   printf("\n");

   return 0;
}


