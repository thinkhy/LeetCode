#include <iostream>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > results;
        if(root == NULL) return results;

        queue<TreeNode*> q;
        set<TreeNode*> lastLevel, curLevel;
        vector<int> r;

        curLevel.insert(root);
        q.push(root);
        r.push_back(root->val);

        while(!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();

            if(lastLevel.find(cur) == lastLevel.end()) {
                lastLevel = curLevel;
                curLevel.clear();

                results.push_back(r);
                r.clear();
            }

            if(cur->left) {
                q.push(cur->left);
                curLevel.insert(cur->left);
                r.push_back(cur->left->val);
            }
            if(cur->right) {
                q.push(cur->right);
                curLevel.insert(cur->right);
                r.push_back(cur->right->val);
            }
        }

        return results;
    }
};


int main() {
    Solution s;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<vector<int> > results = s.levelOrder(root);
    for(int i = 0; i < results.size(); i++) {
        for(int j = 0; j < results[i].size(); j++) 
            cout << results[i][j] << " ";

        cout << endl;
    }

    return 0;
}





