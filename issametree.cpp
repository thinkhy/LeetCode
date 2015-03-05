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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL || q == NULL)                
            return p==q;
        else
            return p->val==q->val
                   && isSameTree(p->left, q->left)
                   && isSameTree(p->right, q->right);
    }
};

int main() {
    Solution s;
    TreeNode *left = new TreeNode(0);

    left->left = NULL;
    left->right = new TreeNode(0);

    TreeNode *right = new TreeNode(0);

    right->left = NULL;
    right->right = new TreeNode(1);

    cout << s.isSameTree(left, right) << endl;

    return 0;
}
