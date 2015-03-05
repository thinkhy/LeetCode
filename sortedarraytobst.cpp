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

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* makeBST(vector<int> &num, int begin, int end) {
        if(begin>end)
            return NULL;
        
        int mid = (end + begin + 1) / 2;
        TreeNode *p = new TreeNode(num[mid-1]);
        p->left = makeBST(num, begin, mid-1);
        p->right = makeBST(num, mid+1, end);

        return p;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        return makeBST(num, 1, num.size());
    }
};

void printBST(TreeNode *p) {
    if(p) {
        cout << p->val << " ";
        printBST(p->left);
        printBST(p->right);
    }

    return;
}

int main() {
    Solution s;
    vector<int> num1;
    TreeNode *p = s.sortedArrayToBST(num1);
    printBST(p);
    cout << endl;

    vector<int> num2(1);
    num2[0] = 0;
    p = s.sortedArrayToBST(num2);
    printBST(p);
    cout << endl;

    vector<int> num3(2);
    num3[0] = 0;
    num3[1] = 1;
    p = s.sortedArrayToBST(num3);
    printBST(p);
    cout << endl;

    vector<int> num4(3);
    num4[0] = 3;
    num4[1] = 5;
    num4[2] = 8;
    p = s.sortedArrayToBST(num4);
    printBST(p);
    cout << endl;

    vector<int> num5(4);
    num5[0] = 0;
    num5[1] = 1;
    num5[2] = 2;
    num5[3] = 3;
    p = s.sortedArrayToBST(num5);
    printBST(p);
    cout << endl;

    return 0;
}

