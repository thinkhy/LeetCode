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
       TreeLinkNode* last;

       qe.push(root);
       int ago = 1;
       while(!qe.empty()) {

           int now = 0;
           TreeLinkNode *last = NULL;
            while(ago--) {
                TreeLinkNode *cur = qe.front();
                qe.pop();

                if(last)
                    last->next = cur;

                if(cur->left) {
                    qe.push(cur->left);
                    now++;
                }
                if(cur->right) {
                    qe.push(cur->right);
                    now++;
                }
                last = cur;
            }
            
            ago = now;
       }

    }
};

void printNodes(TreeLinkNode *root) {
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
}

int main() {
    Solution s;
    TreeLinkNode *root = new TreeLinkNode(1);
    s.connect(root);
    printNodes(root);
    root->left = new TreeLinkNode(2);
    s.connect(root);
    printNodes(root);
    root->right = new TreeLinkNode(3);
    s.connect(root);
    printNodes(root);
    root->left->left = new TreeLinkNode(4);
    s.connect(root);
    printNodes(root);
    root->left->right = new TreeLinkNode(5);
    s.connect(root);
    printNodes(root);
    root->right->right = new TreeLinkNode(7);
    s.connect(root);
    printNodes(root);

    s.connect(root);
    printNodes(root);


    return 0;
}


