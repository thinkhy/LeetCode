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
    void doPreOrderTravel(TreeNode *root, vector<int>& result) { 
        if (root == NULL)
            return;
        else {
            result.push_back(root->val);
            doPreOrderTravel(root->left, result);
            doPreOrderTravel(root->right, result);
        }
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        doPreOrderTravel(root, result);

        return result;
    }
};
int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = s.preorderTraversal(root);
    for(int i = 0; i < result.size(); i ++)
        cout << result[i] << "\t";
    cout << endl;
}
