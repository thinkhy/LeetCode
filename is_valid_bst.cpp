#include <iostream>
#include <string>
#include <sstream>
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
#include <cmath>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*
 * Implement pow(x, n).
 */


#include <iostream>
#include <string>
#include <sstream>
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
    bool isValidBST(TreeNode *root) {
        if (root == NULL) return true;

        TreeNode *tmp;
        if(root->left) {
            if(!isValidBST(root->left) )
                return false;
            else {
                tmp = root->left;
                while(tmp->right) tmp = tmp->right;
                if(tmp->val >= root->val)
                    return false;
            }
        }

        if(root->right) {
            if(!isValidBST(root->right) )
                return false;
            else {
                tmp = root->right;
                while(tmp->left) tmp = tmp->left;
                if(tmp->val <= root->val)
                    return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(50);
    root->left = new TreeNode(40);
    root->left->left = new TreeNode(25);
    root->left->right = new TreeNode(45);
    root->left->right->left = new TreeNode(42);
    cout << s.isValidBST(root) << endl;

    return 0;
}



