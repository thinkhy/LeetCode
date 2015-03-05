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
    void dowork(vector<TreeNode *>& re, 
                TreeNode *root, 
                TreeNode *parent,
                int begin, 
                int end, 
                int left) {
        if(begin > end) {
            root->left = root->right = NULL;
            return;
        }
        bool isLeft = begin < root->val;

        for(int i = begin; i <= end; i++) {
            TreeNode *cur = new TreeNode(i);
            if(isLeft) 
                root->left = cur;
            else
                root->right = cur;
                
            dowork(re, root, cur, begin, i - 1, left - 1);
            dowork(re, root, cur, i+1, end, left - (i - begin + 1));
        }
    }

    vector<TreeNode *> generateTrees(int n) {
           vector<TreeNode *> re; 
           if(n == 0) return re;

           TreeNode *preRoot = new TreeNode(1);

           for(int i = 2; i <= n; i++) {
               TreeNode *root = new TreeNode(i);
               root
               for(int i = 0; i  
           }
    }
};

int main() {
    Solution s;


    return 0;
}





