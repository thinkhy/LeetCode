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
    bool travelTree(TreeNode *left, TreeNode *right) {
        if(left == NULL || right == NULL)
            return left == right;

        if(left->val != right->val)
            return false;
        else
            return travelTree(left->left, right->right)
                    && travelTree(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root) {
        if(root == NULL) return true;
        return travelTree(root->left, root->right);
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(0);
    root->left =  new TreeNode(1);
    root->right =  new TreeNode(1);
    root->left->left = new TreeNode(2);
    root->right->right = new TreeNode(1);
    cout << s.isSymmetric(root) << endl;
}


