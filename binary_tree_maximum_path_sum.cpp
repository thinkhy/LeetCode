#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstring>
using namespace std;

#define DE(a) do { cout << #a << ": " << a << endl; } while(0)

/*******************************************************************************************************************
 
    Given a binary tree, find the maximum path sum.

    The path may start and end at any node in the tree.

    For example:
        Given the below binary tree,

           1
          / \
         2   3
        Return 6.
 ************************************************************************************************************************/

/*
  Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int maxSum = INT_MIN;
        findMaxSum(root, maxSum);
        return maxSum;
    }

    int findMaxSum(TreeNode *root, int& maxSum) {
       if(root == NULL) return INT_MIN; 

       int leftSum, rightSum;
       leftSum = rightSum = INT_MIN;

       if(root->left)
            leftSum = findMaxSum(root->left, maxSum);
       if(root->right)
            rightSum = findMaxSum(root->right, maxSum);

       int tmpMaxSum = max({ root->val,
                            (leftSum == INT_MIN || rightSum == INT_MIN) ? INT_MIN : leftSum+rightSum+root->val,
                            leftSum == INT_MIN ? INT_MIN : leftSum+root->val,
                            rightSum == INT_MIN ? INT_MIN : rightSum+root->val
                          });
       maxSum = max(tmpMaxSum, maxSum);

       return tmpMaxSum;
    }
};

int main() {
    Solution slt;
    TreeNode *root = new TreeNode(1);
    root->left =  new TreeNode(2);
    root->right = new TreeNode(3);
    DE(slt.maxPathSum(root));
    root = new TreeNode(-3);
    DE(slt.maxPathSum(root));
    root = new TreeNode(-2);
    root->right = new TreeNode(-3);
    DE(slt.maxPathSum(root));
    DE(INT_MIN);
    root = new TreeNode(-2);
    root->left = new TreeNode(1);
    DE(slt.maxPathSum(root));

    return 0;
}






