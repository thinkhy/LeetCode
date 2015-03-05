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
        if (root == NULL)
           return result;

        stack<TreeNode*> st;
        //st.push(root);
        while(root != NULL || !st.empty()) {
            if(root != NULL) {
                st.push(root);
                root = root->left;
            }
            else {
                root = st.top();
                st.pop();
                DE(root->val);
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
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<int> result = s.preorderTraversal(root);
    for(int i = 0; i < result.size(); i ++)
        cout << result[i] << "\t";
    cout << endl;
}



