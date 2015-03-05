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
#include <iterator>
#include <cstdio>
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
    TreeNode* clone(TreeNode *root, TreeNode*& target) {
        if(root == NULL) 
            return NULL;

        TreeNode *newroot = new TreeNode(root->val);
        if(target&&target->val == newroot->val) 
            target = newroot;

        newroot->left =  clone(root->left, target);
        newroot->right = clone(root->right, target);

        return newroot;
    }

    vector<TreeNode *> generateTrees(int n) {
           vector<TreeNode *> re; 
           if(n <= 0) {
               re.push_back(NULL);
               return re;
           }
            
           re.push_back(new TreeNode(1));
           for(int i = 2; i <= n; i++) {
               int len = re.size();
               for(int j = 0; j < len; j++) {
                   // 1. add new node as right node iteratively 
                   TreeNode *parentnode = re[j];
                   TreeNode *leftnode = re[j]->right;
                   while(parentnode != NULL) {
                       TreeNode* newparent=parentnode;
                       TreeNode* newroot = clone(re[j], newparent);
                       TreeNode* newnode = new TreeNode(i);
                       newnode->left = newparent->right;
                       newparent->right = newnode;
                       re.push_back(newroot);

                       parentnode = leftnode;
                       if(leftnode)
                           leftnode = leftnode->right; 
                   }

                   // 2. add new node as root node
                   TreeNode *newnode = new TreeNode(i); 
                   newnode->left = re[j];
                   re[j] = newnode;

               }
           }

    }
};

void dfs(TreeNode* root) {
    if(root == NULL) {
        cout << '#' << " ";
        return;
    }
    cout << root->val << " ";
    dfs(root->left);
    dfs(root->right);
}

int main() {
    Solution s;

    vector<TreeNode*> re;
    re = s.generateTrees(0);
    for(int i = 0; i < re.size(); i++) {
        dfs(re[i]);
        cout << endl;
    }
    re = s.generateTrees(1);
    for(int i = 0; i < re.size(); i++) {
        dfs(re[i]);
        cout << endl;
    }
    re = s.generateTrees(2);
    for(int i = 0; i < re.size(); i++) {
        dfs(re[i]);
        cout << endl;
    }
    re = s.generateTrees(3);
    for(int i = 0; i < re.size(); i++) {
        dfs(re[i]);
        cout << endl;
    }

    return 0;
}





