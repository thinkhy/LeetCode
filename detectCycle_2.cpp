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

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/**
 * Detect cycle: 
 *  Problem: https://oj.leetcode.com/problems/linked-list-cycle-ii/
 *  Discuss: https://oj.leetcode.com/discuss/396/is-there-any-better-answer-for-the-linked-list-cycle-ii
 *  Wekipedia: http://en.wikipedia.org/wiki/Cycle_detection
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       if(head == NULL) return NULL;

       ListNode *tortoise = head; 
       ListNode *hare = head; 
       do {
           tortoise = tortoise->next;
           if(hare->next && hare->next->next)
               hare = hare->next->next;
           else
               hare = NULL;

       } while(tortoise && hare && tortoise != hare);

       if(hare == NULL) return NULL;

       tortoise = head;
       while(tortoise != hare) {
           tortoise = tortoise->next;
           hare = hare->next;
       }

       return tortoise;
    }
};



int main() {
    Solution s; 

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next->next;

    ListNode *start = s.detectCycle(head);
    cout << start->val << endl;

    return 0;
}



