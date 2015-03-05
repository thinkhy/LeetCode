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

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    void connect(TreeLinkNode *root) {
       if(!root)  return;  

       queue<TreeLinkNode*> qe;
       unordered_set<TreeLinkNode*> lastLevNodes;
       unordered_set<TreeLinkNode*> curLevNodes;
       TreeLinkNode* last;
       bool newLevel = false;

       qe.push(root);
       curLevNodes.insert(root);
       while(!qe.empty()) {
            TreeLinkNode *cur = qe.front();
            qe.pop();

            if (lastLevNodes.find(cur) != lastLevNodes.end()) {
                last->next = cur;
            }
            else {
                lastLevNodes = curLevNodes;
            }

            if(cur->left) {
                qe.push(cur->left);
                curLevNodes.insert(cur->left);
            }
            if(cur->right) {
                qe.push(cur->right);
                curLevNodes.insert(cur->right);
            }

            last = cur;
       }
    }
};


int main() {
    Solution s;
    TreeLinkNode *root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);

    s.connect(root);
    TreeLinkNode *child;
    while(root) {
        child = root;
        while(child) {
            cout << child->val << "  ";
            child = child->next;
        }
        root = root->left;
    }
    cout << endl;


    return 0;
}


