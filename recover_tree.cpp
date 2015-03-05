#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
#include <iterator>
#include <cstdio>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*
   Two elements of a binary search tree (BST) are swapped by mistake.
   Recover the tree without changing its structure.

   Note:
       A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
       confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/


/* Definition for binary tree */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode *root) {
        if(root == NULL || (root->left == root->right)) return;
        stack<TreeNode*> st;    
        TreeNode *cur = root;
        TreeNode *pre = NULL;
        TreeNode *node1 = NULL;
        TreeNode *node2 = NULL;
        while(cur != NULL || !st.empty()) {
            if(cur != NULL) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                cur = st.top();
                st.pop();
                if(pre != NULL) {
                    if(pre->val > cur->val) {
                        if(node1 == NULL)
                            node1 = pre;

                        node2 = cur;
                    }
                }
                pre = cur;
                cur = cur->right;
            }
        }
        swap(node1->val, node2->val);

        return;
    }
};

void inorder_travesal(TreeNode *root) {
    if(root == NULL) return;

    inorder_travesal(root->left);
    cout << root->val << " ";
    inorder_travesal(root->right);

    return;
}


int main() {
    Solution s;
    TreeNode *root = new TreeNode(2);
    root->right = new TreeNode(1);
    root->right->right = new TreeNode(3);
    /*
    root->left->left = new TreeNode(13);
    root->right = new TreeNode(12);
    root->right->right = new TreeNode(7);
    */

    inorder_travesal(root);
    cout << "ok" << endl;
    s.recoverTree(root);
    inorder_travesal(root);
    cout << endl;

    return 0;
}







