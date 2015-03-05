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
    void dfs(vector< vector<int>> &re, 
             TreeNode *root, 
             int sum, 
             vector<int> &road) {
        if(root == NULL)
            return;

        road.push_back(root->val);
        if(root->left == root->right
                && root->val == sum)  {
            re.push_back(road);
        }
        else {
            dfs(re, root->left, sum - root->val,  road);
            dfs(re, root->right, sum - root->val, road);
        }

        road.pop_back();
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector< vector<int>> result;
        vector<int> road;
        dfs(result, root, sum, road);      

        return result;
    }
};

int main() {
    Solution s;
    
    vector<vector<int> > re;
    int sum;
    TreeNode* root;
    sum = 22;

    root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    re = s.pathSum(root, sum);
    for(int i = 0; i < re.size(); i++) {
        for(int j = 0; j < re[i].size(); j++) {
            cout << re[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


