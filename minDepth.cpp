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
    int minDepth(TreeNode *root) {
        if(root == NULL)
            return 0;

        if(root->left && root->right)
            return 1 + min(minDepth(root->left), minDepth(root->right));
        else if(root->left)
            return 1 + minDepth(root->left);
        else if(root->right)
            return 1 + minDepth(root->right);
        else
            return 1;
    }
};


int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    cout << s.minDepth(root) << endl;
    root->left = new TreeNode(2);
    cout << s.minDepth(root) << endl;
    root->right = new TreeNode(3);
    cout << s.minDepth(root) << endl;
    root->right->right = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << s.minDepth(root) << endl;

    return 0;
}


