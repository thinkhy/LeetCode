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
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL)        
            return false;

        stack<pair<TreeNode*, int> > st;
        st.push(make_pair(root, sum);

        while(!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            /*if(root->val == sum && root->left == root->right)
                return true;
                */
        }

    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    cout << s.hasPathSum(root, 22) << endl;
    cout << s.hasPathSum(root, 27) << endl;
    cout << s.hasPathSum(root, 26) << endl;
    cout << s.hasPathSum(root, 18) << endl;

    root = NULL;
    cout << s.hasPathSum(root, 0) << endl;

    return 0;
}
