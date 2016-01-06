#include <stdio.h>
#include <stdlib.h>

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

typedef struct typeBST{
  int value;
  int count;
  int leftChild;
  struct typeBST *left;
  struct typeBST *right;
} Bst;

Bst* GenBstNode(int value) {
   Bst *root = (Bst*)malloc(sizeof(Bst));
   root->value = value;
   root->count = 1;
   root->leftChild = 0;
   root->left = NULL;
   root->right = NULL;

   return root;
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

    Bst *root = GenBstNode(nums[numsSize-1]);
    results[numsSize-1] = 0;

    for(i = numsSize-2; i >= 0; i--) {
        // results[i] = DFS(root, nums[i]);
        cnt = 0;
        value = nums[i];
        Bst *cur = root;

        while (1) {
            if (cur->value == value) {
                cur->count++;
                cnt += cur->leftChild;
                break;
            }
            else if (cur->value < value) {
                cnt += cur->count + cur->leftChild;
                if (cur->right == NULL) {
                    cur->right = GenBstNode(value);
                    break;
                }
                else
                    cur = cur->right;
            }
            else if (cur->value > value) {
                cur->leftChild++;
                if (cur->left == NULL) {
                    cur->left = GenBstNode(value);
                    break;
                }
                else
                    cur = cur->left;
           }
        }

        results[i] = cnt;
    }

    return results;
}

int DFS(Bst *root, int value) {
    if (root->value == value) {
        root->count++;
        return root->leftChild;
    }
    else if (root->value < value) {
        if (root->right == NULL) {
            root->right = GenBstNode(value);
            return root->count + root->leftChild;
        }
        else {
            return root->count + root->leftChild + DFS(root->right, value);
        }
    }
    else if (root->value > value) {
        root->leftChild++;
        if (root->left == NULL) {
            root->left = GenBstNode(value);
            return 0;
        }
        else
            return DFS(root->left, value);
    }
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


