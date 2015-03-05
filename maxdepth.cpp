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
    int maxDepth(TreeNode *root) {
        if(root == NULL)
            return 0;
        else 
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(0);

    root->left = NULL;
    root->right = new TreeNode(0);

    cout << s.maxDepth(root) << endl;

    return 0;
}
