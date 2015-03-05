#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*****************************************************************************
 *
 * Given postorder and inorder traversal of a tree, construct the binary tree.
 * Note: You may assume that duplicates do not exist in the tree.
 *
 *****************************************************************************/

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
    TreeNode *do_work(vector<int> &postorder, int post_start, int post_end, 
                      vector<int> &inorder,   int in_start,   int in_end) {
        if(post_start == post_end || in_start == in_end)
            return NULL;

        int root_val = postorder[post_end-1];
        TreeNode* root = new TreeNode(root_val);
        int i;
        for(i = in_start; i < in_end; i++) {
            if(inorder[i] == root_val)
                break;
        }
        int len = i-in_start;
        root->left =  do_work(postorder, post_start, post_start+len,
                              inorder,   in_start,     i);
        root->right = do_work(postorder, post_start+len, post_end-1,
                              inorder,   i+1,              in_end);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return do_work(postorder,0, postorder.size(),
                       inorder,  0, inorder.size());
    }
};

void dfs(TreeNode *root) {
    if(root == NULL) {
        cout << "#" << " ";
        return;
    }
    cout << root->val << " ";
    dfs(root->left);
    dfs(root->right);

    return;
}

int main() {
    Solution s;
    vector<int> postorder;
    postorder.resize(3);
    postorder[0] = 2;
    postorder[1] = 3;
    postorder[2] = 1;

    vector<int> inorder;
    inorder.resize(3);
    inorder[0] = 2;
    inorder[1] = 1;
    inorder[2] = 3;

    TreeNode *root = s.buildTree(inorder, postorder);
    dfs(root);
    cout << endl;

    postorder.resize(0);
    inorder.resize(0);
    root = s.buildTree(inorder, postorder);
    dfs(root);
    cout << endl;

    postorder.resize(1);
    inorder.resize(1);
    postorder[0] = 1;
    inorder[0] = 1;
    root = s.buildTree(inorder, postorder);
    dfs(root);
    cout << endl;

    postorder.resize(2);
    inorder.resize(2);
    postorder[0] = 2;
    postorder[1] = 1;
    inorder[0] = 2;
    inorder[1] = 1;
    root = s.buildTree(inorder, postorder);
    dfs(root);
    cout << endl;

    postorder.resize(2);
    inorder.resize(2);
    postorder[0] = 2;
    postorder[1] = 1;
    inorder[0] = 1;
    inorder[1] = 2;
    root = s.buildTree(inorder, postorder);
    dfs(root);
    cout << endl;

    postorder.resize(3);
    inorder.resize(3);
    postorder[0] = 3;
    postorder[1] = 2;
    postorder[2] = 1;
    inorder[0] = 3;
    inorder[1] = 2;
    inorder[2] = 1;
    root = s.buildTree(inorder, postorder);
    dfs(root);
    cout << endl;
    cout << endl;

    return 0;
}


