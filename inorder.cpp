#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
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
    vector<int> inorderTraversal(TreeNode *root) {

       if (!root) return vector<int>(); 

       vector<int> result;
       stack<TreeNode*> st; 

       set<TreeNode*> hasTravel;
       st.push(root);

       while(!st.empty()) {
          TreeNode *cur = st.top();  
          while(cur->left && hasTravel.find(cur->left) == hasTravel.end()) {
              cur = cur->left;
              st.push(cur);
          }

          cur = st.top();
          result.push_back(cur->val);
          hasTravel.insert(cur);
          st.pop();


          if(cur->right)  
              st.push(cur->right);
       }

       return result;
    }
};


int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);
    root->left = left;
    root->right = right;

    Solution s;
    s.inorderTraversal(root);

    return 0;
}
