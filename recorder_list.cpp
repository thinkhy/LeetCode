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
#include <algorithm>
#include <limits>
#include <utility>
#include <cstdio>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << (a) << endl;

/*******************************************************************************************************************
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You must do this in-place without altering the nodes' values.
 * 
 * For example,
 *   Given {1,2,3,4}, reorder it to {1,4,2,3}.
 *
 ************************************************************************************************************************/

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
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL) return;

        // find the middle node
        ListNode *onestep, *twostep;
        onestep = twostep = head;

        while(twostep->next && twostep->next->next) {
            onestep = onestep->next;
            twostep = twostep->next->next;
        }
        
        // split the list 
        ListNode *p1 = head;
        ListNode *p2 = onestep->next;
        onestep->next = NULL;
        
        // reverse the right list
        ListNode *prevnode = NULL; 
        ListNode *p, *q;
        p = p2;
        while(p) {
            q = p->next;
            p->next = prevnode;
            prevnode = p;
            p = q;
        }
        p2 = prevnode;

        prevnode = NULL;
        // merge the two lists
        while(p1 != NULL && p2 != NULL) {
            q = p1->next;
            p = p2->next;

            if(prevnode)
                prevnode->next = p1;

            p1->next = p2;
            prevnode = p2;
            p1 = q;
            p2 = p;
        }
        if(p1 != NULL)
            prevnode->next = p1;

        return;
    }
};

int main() {
    Solution slt;
    ListNode *h, *p;
    h = new ListNode(1);
    p = h;
    p = p->next = new ListNode(2);
    p = p->next = new ListNode(3);
    //p = p->next = new ListNode(4);

    slt.reorderList(h);
    p = h;
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }

    return 0;
}


