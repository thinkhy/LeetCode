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


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
       ListNode *cur = head; 
       while(cur) {
           while(cur->next&&cur->val == cur->next->val) {
               cur->next = cur->next->next;
           }
           cur = cur->next;
       }
       return head;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    ListNode *tmp = head->next->next = new ListNode(2);
    tmp->next = new ListNode(3);
    tmp->next->next = new ListNode(3);
    head = s.deleteDuplicates(head);
    while(head) {
        cout << head->val << " ";
        head=head->next;
    }
    cout << endl;
}
