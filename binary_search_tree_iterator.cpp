#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <memory>
#include <limits>
#include <utility>
#include <cstdio>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << (a) << endl;
#define EXPECT(a, b) cout << #a << ": result: " << (a) \
                                << "  expect: " << (b)   << endl;

/*******************************************************************************************************************
 *
 * Binary Search Tree Iterator
 * 
 *
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 * 
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 * 
 * Credits:
 *  Special thanks to @ts for adding this problem and creating all test cases.
 *
 ************************************************************************************************************************/

/**
 * Definition for binary tree
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


/*
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, 
 * where h is the height of the tree. 
 *
 */
class BSTIterator {
    TreeNode *current;
    stack<TreeNode*> ancests;

private:
    void pushLeftNodes(TreeNode * &current) {
       if(current == NULL) return; 
       while(current->left) { 
           ancests.push(current);
           current = current->left;
       }
    }

public:
    BSTIterator(TreeNode *root) {
       // initialize: locate current node to the left(smallest) node 
       current = root;
       pushLeftNodes(current);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return current != NULL;
    }

    /** @return the next smallest number */
    int next() {
        int ret;
        if(current != NULL)
            ret = current->val;

        // go to right node directly if has right child
        // note: at here we needn't change stack because we will not track back to ancester of right node
        if(current && current->right) {
            current = current->right;
            pushLeftNodes(current);
        }
        // back to nearest ancestor in the stack, pop it and assign it to current node
        else if(!ancests.empty()) {
            current = ancests.top();    
            ancests.pop();
        }
        // otherwise, return undefined value
        else 
            current = NULL;

        return ret;
    }
};

int main() {
    /*Solution slt;*/
    shared_ptr<TreeNode> root(new TreeNode(3));

    BSTIterator i = BSTIterator(NULL);
    while (i.hasNext()) 
        cout << i.next() << " ";
    cout << endl;

    /* Your BSTIterator will be called like this: */
    i = BSTIterator(root.get());
    while (i.hasNext()) 
        cout << i.next() << " ";
    cout << endl;

    shared_ptr<TreeNode> left(new TreeNode(2));
    shared_ptr<TreeNode> right(new TreeNode(10));
    root->left = left.get();
    root->right = right.get();
    i = BSTIterator(root.get());
    while (i.hasNext()) 
        cout << i.next() << " ";
    cout << endl;

    right->left = new TreeNode(6);
    right->left->left = new TreeNode(4);
    right->left->right = new TreeNode(7);
    i = BSTIterator(root.get());
    while (i.hasNext()) 
        cout << i.next() << " ";
    cout << endl;

    return 0;
}

