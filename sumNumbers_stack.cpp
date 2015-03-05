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
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode *root, int& sum, int cur) {
        if(root == NULL)
            return; 

        cur = cur * 10 + root->val;

        if(root->left == root->right)
            sum += cur;
        else {
            dfs(root->left, sum, cur);
            dfs(root->right, sum, cur);
        }
    }

    int sumNumbers(TreeNode *root) {
        int sum = 0;
        if(root == NULL)
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            if(node->left == node->right)    
               sum += node->val;
            else {
               if(node->left) {
                  node->left->val = node->val*10 + node->left->val;
                  q.push(node->left);
               }
               if(node->right) {
                  node->right->val = node->val*10 + node->right->val;
                  q.push(node->right);
               }
            }
         }

        return sum;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << s.sumNumbers(root) << endl;

    return 0;
}


