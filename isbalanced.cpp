#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool dfs(TreeNode* root, int& height) {
        if(root == NULL) {
            height = 0;
            return true;
        }

        int lheight, rheight;
        bool isLeftBalanced = dfs(root->left, lheight);
        if(isLeftBalanced == false)
          return false;

        bool isRightBalanced = dfs(root->right, rheight);
        if(isRightBalanced == false)
          return false;

        height = max(lheight, rheight) + 1;

        return isLeftBalanced && isRightBalanced && abs(lheight-rheight) <= 1;
    }

    bool isBalanced(TreeNode *root) {
      if(root == NULL)
          return true;

      int lheight = 0;
      int rheight = 0;
      bool isLeftBalanced = dfs(root->left, lheight);  
      if(isLeftBalanced == false)
          return false;

      bool isRightBalanced = dfs(root->right, rheight);  
      if(isRightBalanced == false)
          return false;

      return isLeftBalanced && isRightBalanced && abs(lheight-rheight) <= 1;
    }
};

int main() {
    Solution s;
    cout << s.isBalanced(NULL) << endl;

    TreeNode *root = new TreeNode(0);
    cout << s.isBalanced(root) << endl;

    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    cout << s.isBalanced(root) << endl;

    root->right->left = new TreeNode(3);
    root->right->left->left = new TreeNode(4);
    cout << s.isBalanced(root) << endl;
    return 0;
}

