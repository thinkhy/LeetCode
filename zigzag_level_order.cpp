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
 * inorder:   2 1 
 * postorder: 2 
 * v: 1   
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > re;
        queue<TreeNode*> qe;
        vector<int> same_level;

        if(root == NULL) 
            return re;

        qe.push(root);
        int age = 1;
        int next = 0;
        bool clockwise = true;

        while(!qe.empty()) {
           TreeNode *cur = qe.front(); 
           qe.pop();

           if(cur->left) {
               next++;
               qe.push(cur->left);
           }
           if(cur->right) {
               next++;
               qe.push(cur->right);
           }

           same_level.push_back(cur->val); 
           age--;
           if(age == 0) {
               age = next;
               next = 0;
               if(clockwise == false)
                   reverse(same_level.begin(), same_level.end());
               clockwise = !clockwise;
               re.push_back(same_level);
               same_level.clear();
           }

        }

        return re;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left  = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int> > re = s.zigzagLevelOrder(root);

    for(int i = 0; i < re.size(); i++) {
        for(int j = 0; j < re[i].size(); j++) {
            cout << re[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


