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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> st;
        unordered_set<TreeNode*> travered;
        vector<int> re;

        if(root == NULL) return re;
        
        st.push(root);
        travered.insert(NULL);
        while(!st.empty()) {
            TreeNode* cur = st.top();
            travered.insert(cur);
            if((travered.find(cur->right) != travered.end()
                  && travered.find(cur->left) != travered.end() )){
                re.push_back(cur->val);
                st.pop();
            }
            else {
                if(cur->right) st.push(cur->right);
                if(cur->left)  st.push(cur->left);
            }
        }

        return re;
    }
};


int main() {
    Solution s; 
    vector<int> r;

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    r = s.postorderTraversal(root);
    for(int i = 0; i < r.size(); i++) {
        cout << r[i] << " ";
    }
    cout << endl;

    root->left = new TreeNode(22);
    root->left->left = new TreeNode(33);
    root->left->right = new TreeNode(44);
    r = s.postorderTraversal(root);
    cout << r.size() << endl;
    for(int i = 0; i < r.size(); i++) {
        cout << r[i] << " ";
    }
    cout << endl;

    return 0;
}



