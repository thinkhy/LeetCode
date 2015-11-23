/*****************************************************************
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 * The update(i, val) function modifies nums by updating the element at index i to val.
 *
 * Example:
 *    Given nums = [1, 3, 5]
 *        sumRange(0, 2) -> 9
 *        update(1, 2)
 *        sumRange(0, 2) -> 8
 * Note:
 *   The array is only modifiable by the update function.
 *   You may assume the number of calls to update and sumRange function is distributed evenly.
 *
 * Tag: Segment Tree
 * Reference: https://www.google.com.hk/$gws_rd=cr,ssl#newwindow=1&safe=strict&q=segment+tree
 *
 ****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define  DE(x) printf(#x" %d\n", x);

// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {
    return s + (e - s)/2;
}

/* st      --> Pointer to segment tree
 * si      --> Index of current node in the segment tree.
 * ss & se --> Starting and ending indexes of the segment represented by current
 *             node
 * qs & qe --> Starting and ending indexes of query range
 */
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si) {

    /* current range within the query range */
    if (qs <= ss && qe >= se)
        return st[si];

    /* if current range is outside of the given range */
    if (qe < ss || qs > se)
        return 0;

    /* if a part of this segment overlaps with the given range */
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, si*2+1) +
           getSumUtil(st, mid+1, se, qs, qe, si*2+2);
}

/*
 *
 * ss & se --> Starting and ending indexes of the segment represented
 * by current node, i.e., st[si]
 * si     --> Index of current node in the segment tree
 */
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si) {
  if (i < ss || i > se)
      return;

  st[si] += diff;
  if(ss != se) {
      int mid = getMid(ss, se);
      updateValueUtil(st, ss, mid, i, diff, si*2+1);
      updateValueUtil(st, mid+1, se, i, diff, si*2+2);
  }
}

void updateValue(int arr[], int *st, int n, int i, int newVal) {
    if (i < 0 || i > n-1)
        return;
    int diff = newVal - arr[i];
    arr[i] = newVal;

    updateValueUtil(st, 0, n-1, i, diff, 0);
}

// A recursive function that constructs Segment Tree for array[ss..se].
// where si is index of current node in segment tree st
int constructSTUtil(int arr[], int ss, int se, int *st, int si) {
   if (ss == se) {
       st[si] = arr[ss];
       return arr[ss];
   }

   int mid = getMid(ss, se);
   st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) +
            constructSTUtil(arr, mid+1, se, st, si*2+2);
   return st[si];
}

/* Function to construct segment tree from given array. This function allocates
 * memory for segment tree and calls constructSTUtil() to fill the allocated
 * memory
 */
int *constructST(int arr[], int n) {
    // Height of segment tree
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;

    int *st = (int*)malloc(max_size * sizeof(int));
    if (st == NULL)
        return NULL;

    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}


struct NumArray {
    int *nums;
    int *segmentTree;
    int size;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    struct NumArray* newArray = (struct NumArray*)malloc(sizeof(struct NumArray));
    if (newArray == NULL)
        return NULL;

    newArray->nums = nums;
    newArray->size = numsSize;
    newArray->segmentTree = constructST(nums, numsSize);

    return newArray;
}

void update(struct NumArray* numArray, int i, int val) {
    updateValue(numArray->nums,
                numArray->segmentTree,
                numArray->size,
                i,
                val);

    return;
}

int sumRange(struct NumArray* numArray, int i, int j) {
   if(numArray == NULL || i > j || j >= numArray->size)
       return -1;
   return getSumUtil(numArray->segmentTree, 0, numArray->size-1, i, j, 0);
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    // free(numArray->nums);
    free(numArray->segmentTree);
    free(numArray);
}


int main() {
    int nums[] = {9, -8};
    int numsSize = sizeof(nums)/sizeof(*nums);

    struct NumArray* numArray = NumArrayCreate(nums, numsSize);
    update(numArray, 0, 3);
    DE(sumRange(numArray, 1, 1));
    return 0;

    DE(sumRange(numArray, 0, 1));
    update(numArray, 1, -3);
    DE(sumRange(numArray, 0, 1));

    NumArrayFree(numArray);

    return 0;
}


// Your NumArray object will be instantiated and called as such:
// // struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// // sumRange(numArray, 0, 1);
// // update(numArray, 1, 10);
// // sumRange(numArray, 1, 2);
// // NumArrayFree(numArray);

