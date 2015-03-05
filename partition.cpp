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

/******************************************************
 * Given a linked list and a value x, partition it 
 * such that all nodes less than x come before nodes 
 * greater than or equal to x.
 *
 * You should preserve the original relative order of 
 * the nodes in each of the two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 *
 ******************************************************/

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
    ListNode *partition(ListNode *head, int x) {
        ListNode *headSmall = new ListNode(0);     
        ListNode *headBig = new ListNode(0);     
        ListNode *p1 = headSmall;
        ListNode *p2 = headBig;
        ListNode *ret;

        while(head != NULL) {
            if(head->val < x) 
                p1 = p1->next = head;
            else
                p2 = p2->next = head;
            head = head->next;
        }
        p2->next = NULL;
        if(p1 != headBig) {
            p1->next = headBig->next;
            ret = headSmall->next;
        }
        else {
            ret = headBig->next;
        }
        delete headSmall;
        delete headBig;

        return ret;
    }

};

int main() {
    Solution s;
    
/***************************************
 *
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 *
 **************************************/
   ListNode *h = new ListNode(1); 
   ListNode *p = h;
   p = p->next = new ListNode(4);
   p = p->next = new ListNode(3);
   p = p->next = new ListNode(2);
   p = p->next = new ListNode(5);
   p = p->next = new ListNode(2);

   ListNode *r = s.partition(h, 3);
   p = r;
   while(p) {
       cout << p->val << " ";
       p = p->next;
   }
   cout << endl;
   return 0;
}



