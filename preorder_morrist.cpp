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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;

        TreeNode *right_most;
        while(root) {
            if(root->left) {
                right_most = root->left;
                while(right_most->right && right_most->right != root) {
                    right_most = right_most->right;
                }
                if(right_most->right == NULL) {
                    right_most->right = root;
                    result.push_back(root->val);
                    root = root->left;
                }
                else {
                    right_most->right = NULL;
                    root = root->right;
                }
            }
            else {
                result.push_back(root->val);
                root = root->right;
            }
        }

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
