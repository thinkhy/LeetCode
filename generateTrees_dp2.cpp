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

void dfs(TreeNode* root);

class Solution {
public:
    TreeNode* clone(TreeNode *root, int offset) {
        if(root == NULL) 
            return NULL;

        TreeNode *newroot = new TreeNode(root->val+offset);

        newroot->left =  clone(root->left,  offset);
        newroot->right = clone(root->right, offset);

        return newroot;
    }

    vector<TreeNode *> generateTrees(int n) {
           vector<vector<TreeNode *> > re(n+1); 
           re[0] = vector<TreeNode*>(1);
           re[0][0] = NULL;

           if(n <= 0) return re[0];
            
           for(int i = 1; i <= n; i++) {
               // divide child nodes into two parts: left(j-1) and right(i-j)
               for(int j = 1; j <= i; j++) {
                   // iterate left child tree
                   int lenl = re[j-1].size();
                   for(int k = 0; k < lenl; k++) {
                       // iterate ritht child tree
                       int lenr = re[i-j].size();
                       for(int h = 0; h < lenr; h++) {
                           TreeNode *newroot = new TreeNode(j);
                           newroot->left =  re[j-1][k]; 
                           newroot->right = clone(re[i-j][h], j); 
                           // cout << endl << "right child: " << endl;
                           // dfs(re[i-j][h]);
                           re[i].push_back(newroot);
                           // cout << endl << i << "new root: " << endl;
                           // dfs(re[i].back());
                       }
                   }
               }
           }

           return re[n];
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

    re.clear();
    re = s.generateTrees(3);
    for(int i = 0; i < re.size(); i++) {
        dfs(re[i]);
        cout << endl;
    }

    return 0;
}





