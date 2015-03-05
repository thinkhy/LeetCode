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
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    TreeNode *sortedListToBST(ListNode *head) {
        return convert(head);    
    }

    TreeNode *convert(ListNode *head) {
        TreeNode *root;
        
        if(head == NULL)
            return NULL;
        if(head->next == NULL) {
            root = new TreeNode(head->val);    
            return root;
        }
            
        // Get the middle node
        ListNode *step1 = head;
        ListNode *step2 = step1->next;
        cout << "step1: " << step1->val << endl;
        while(step2->next&&step2->next->next) { 
           step1 = step1->next; 
           step2 = step2->next->next; 
        }

        root = new TreeNode(step1->next->val);
        cout << "New root: " << root->val << endl;
        ListNode *next = step1->next->next;
        step1->next = NULL;

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(next);
         
        return root;
    }
};

void preorder(TreeNode *root) {
    if(root) {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode *root) {
    if(root) {
        if(root->left)
            inorder(root->left);
        else 
            cout << ",#";

        cout << "," << root->val;

        if(root->right) 
            inorder(root->right);
        else
            cout << ",#";
    }
}

int main() {
    Solution s;
    ListNode *p = new ListNode(3);
    ListNode *H = p;
    p = p->next = new ListNode(5);
    p = p->next = new ListNode(8);
    TreeNode *root = s.sortedListToBST(H); 
    inorder(root);

    return 0;
}





