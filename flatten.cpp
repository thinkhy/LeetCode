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
#include <cstring>
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
    void flatten(TreeNode *root) {
        if(root == NULL)
            return;

        TreeNode *preNode = NULL;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()) {
            TreeNode *cur = st.top();
            if(cur->left == cur->right
               || (cur->right == preNode && cur->left == NULL) 
               || (preNode != NULL && cur->left == preNode)) {
                cur->right = preNode;
                preNode = cur;
                st.pop();
            }
            else {
                if(cur->left)
                    st.push(cur->left);
                if(cur->right)
                    st.push(cur->right);
            }

        }
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    s.flatten(root);
    while(root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
    return 0;
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    s.flatten(root);
    while(root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;

    return 0;
}

