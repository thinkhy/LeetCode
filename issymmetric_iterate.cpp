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

class Solution { 
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL) return true;

        stack<TreeNode*> st;
        st.push(root->left); 
        st.push(root->right); 

        while(!st.empty()) {
            TreeNode* node1 = st.top();
            st.pop();
            TreeNode* node2 = st.top();
            st.pop();

            if(node1 == NULL || node2 == NULL) {
                if(node2 == node1)
                    continue;
                else
                    return false;
            }
            else {
                if(node1->val != node2->val)
                    return false;
                else {
                    st.push(node1->left);
                    st.push(node2->right);
                    st.push(node1->right);
                    st.push(node2->left);
                }
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(0);
    root->left =  new TreeNode(1);
    root->right =  new TreeNode(1);
    cout << s.isSymmetric(root) << endl;

    root->left->left = new TreeNode(2);
    cout << s.isSymmetric(root) << endl;

    root->right->right = new TreeNode(1);
    cout << s.isSymmetric(root) << endl;

    root->right->right->val = 2; 
    cout << s.isSymmetric(root) << endl;
}


