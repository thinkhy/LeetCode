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
 * inorder:   2 1 3
 * postorder: 2 
 * v: 1  3 
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0)return NULL;
        TreeNode* p;
        TreeNode* root;
        vector<int> vint;
        vector<TreeNode*> vtn;
        root = new TreeNode(postorder.back());
        vtn.push_back(root);
        postorder.pop_back();
        while(true)
        {
            if(inorder.back() == vtn.back()->val)
            {
                p = vtn.back();
                vtn.pop_back();
                inorder.pop_back();
                if(inorder.size() == 0) break;
                if(vtn.size())
                    if(inorder.back() == vtn.back()->val)continue;
                p->left = new TreeNode(postorder.back());
                postorder.pop_back();
                vtn.push_back(p->left);
            }
            else
            {
                p = new TreeNode(postorder.back());
                postorder.pop_back();
                vtn.back()->right = p;
                vtn.push_back(p);
            }
        }

        return root;
    }

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


