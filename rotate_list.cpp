#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*******************************************************************************************************************
 *
 * Rotate List Total 
 *
 *  Accepted: 22568 Total Submissions: 103067 
 *
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 * For example:
 *   Given 1->2->3->4->5->NULL and k = 2,
 *   return 4->5->1->2->3->NULL.
 *
 ************************************************************************************************************************/

/**
 * Definition for singly-linked list.
 *
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL) return NULL;
        if(k <= 0) return head;

        ListNode *dumm = new ListNode(0);
        ListNode *p = head;
        ListNode *q;

        int len = 1;
        while(p->next) { 
            p = p->next;
            len++; 
        }
         
        k %= len;
        k = len - k;
        p = p->next = head;
        while(k--) {
            q=p;
            p=p->next;
        }
        q->next = NULL;

        return p;
    }
};

int main() {
    Solution slt;

    // Given 1->2->3->4->5->NULL and k = 2,
    ListNode *head = new ListNode(1);
    int k;

    ListNode *p = head;
    p = p->next = new ListNode(2);
    p = p->next = new ListNode(3);
    p = p->next = new ListNode(4);
    p = p->next = new ListNode(5);

    p = head;
    while(p) {
        cout << p->val << " ";
        p=p->next;
    }
    cout << "OK" << endl;

    ListNode *res = slt.rotateRight(head, 2); 

    p = res;
    while(p) {
        cout << p->val << " ";
        p=p->next;
    }

    return 0;
}






