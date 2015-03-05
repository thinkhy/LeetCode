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
using namespace std;


/*
    Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
    If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
    You may not alter the values in the nodes, only nodes itself may be changed.
    Only constant memory is allowed.

    For example,
        Given this linked list: 1->2->3->4->5
        For k = 2, you should return: 2->1->4->3->5
        For k = 3, you should return: 3->2->1->4->5
*/

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
          if (head == NULL || k <= 0) return head;
          ListNode *p = head;

          int len = 0;
          ListNode *dummy = new ListNode(0);
          ListNode *pre = dummy;
          ListNode *next_pre;

          while(p) { len++; p = p->next; }
          if (len - k >= 0) {
              int i;
              for(dummy->next = NULL, p = head, i = len-k; i >= 0; i -= k) {
                  next_pre = p;
                  for(int j = 0; j < k; j++) {
                      ListNode *q = p->next;  
                      p->next = pre->next;
                      pre->next = p;
                      p = q;
                  }
                  pre = next_pre;
              }
              pre->next = p;
          }
          else {
              dummy->next = head;
          }

          ListNode *re = dummy->next;
          delete dummy;

          return re;
    }
};


int main() {
    Solution s;

    ListNode *h = new ListNode(1);
    ListNode *p = h;
    p = p->next = new ListNode(2);
    /*p = p->next = new ListNode(3);
    p = p->next = new ListNode(4);
    p = p->next = new ListNode(5);
    */

    ListNode *re = s.reverseKGroup(h, 2);
    p = re;
    while(p) {
       cout << p->val << " "; 
       p = p->next;
    }
    cout << endl;

    return 0;
}


