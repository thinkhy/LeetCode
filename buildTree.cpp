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
 * Given preorder and inorder traversal of a tree, construct the binary tree.
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
    TreeNode *do_work(vector<int> &preorder, int pre_start, int pre_end, 
                      vector<int> &inorder,  int in_start,  int in_end) {
        if(pre_start == pre_end || in_start == in_end)
            return NULL;

        TreeNode* root = new TreeNode(preorder[pre_start]);
        int i;
        for(i = in_start; i < in_end; i++) {
            if(inorder[i] == preorder[pre_start]) 
                break;
        }
        int len = i-in_start;
        root->left = do_work(preorder, pre_start+1, pre_start+1+len,
                             inorder,  in_start,     i);
        root->right = do_work(preorder, pre_start+1+len, pre_end,
                              inorder,  i+1,             in_end);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return do_work(preorder, 0, preorder.size(),
                       inorder,  0, inorder.size());
        /*
        if(preorder.empty() || inorder.empty())
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int>::iterator pos = 
            find(inorder.begin(), inorder.end(), preorder[0]);

        int len = pos-inorder.begin();
        if(len > 1) {
            vector<int> left_preorder(preorder.begin()+1, preorder.begin()+len);
            vector<int> left_inorder(inorder.begin(), pos);
            root->left=buildTree(left_preorder, left_inorder);

            vector<int> right_preorder(preorder.begin()+len, preorder.end());
            vector<int> right_inorder(pos+1, inorder.end());
            root->right=buildTree(right_preorder, right_inorder);
        }
        vector<int> left_preorder;
        vector<int> left_inorder;
        for(int i = 0; i < len; i++) {
            left_inorder.push_back(inorder[i]);
            left_preorder.push_back(preorder[1+i]);
        }
        root->left=buildTree(left_preorder, left_inorder);

        vector<int> right_preorder;
        vector<int> right_inorder;
        int right_len = preorder.size() - len - 1;

        for(int i = 0; i < right_len; i++) {
            right_inorder.push_back(inorder[len+i+1]);
            right_preorder.push_back(preorder[len+i+1]);
        }
        root->right=buildTree(right_preorder, right_inorder);

                        
        return root;
        */
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
    vector<int> preorder;
    preorder.resize(3);
    preorder[0] = 1;
    preorder[1] = 2;
    preorder[2] = 3;

    vector<int> inorder;
    inorder.resize(3);
    inorder[0] = 2;
    inorder[1] = 1;
    inorder[2] = 3;

    TreeNode *root = s.buildTree(preorder, inorder);
    dfs(root);
    cout << endl;

    preorder.resize(0);
    inorder.resize(0);
    root = s.buildTree(preorder, inorder);
    dfs(root);
    cout << endl;

    preorder.resize(1);
    inorder.resize(1);
    preorder[0] = 1;
    inorder[0] = 1;
    root = s.buildTree(preorder, inorder);
    dfs(root);
    cout << endl;

    preorder.resize(2);
    inorder.resize(2);
    preorder[0] = 1;
    preorder[1] = 2;
    inorder[0] = 2;
    inorder[1] = 1;
    root = s.buildTree(preorder, inorder);
    dfs(root);
    cout << endl;

    preorder.resize(2);
    inorder.resize(2);
    preorder[0] = 1;
    preorder[1] = 2;
    inorder[0] = 1;
    inorder[1] = 2;
    root = s.buildTree(preorder, inorder);
    dfs(root);
    cout << endl;

    preorder.resize(3);
    inorder.resize(3);
    preorder[0] = 1;
    preorder[1] = 2;
    preorder[2] = 3;
    inorder[0] = 3;
    inorder[1] = 2;
    inorder[2] = 1;
    root = s.buildTree(preorder, inorder);
    dfs(root);
    cout << endl;
    cout << endl;

    return 0;
}


