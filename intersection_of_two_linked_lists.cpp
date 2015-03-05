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

#define DE(a) do { cout << #a << ": " << a << endl; } while(0)

/*******************************************************************************************************************
 *
 * Intersection of Two Linked Lists 
 * 
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * 
 * 
 * For example, the following two linked lists:
 * 
 * A:          a1 → a2
 *                    ↘
 *                      c1 → c2 → c3
 *                    ↗            
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.
 * 
 * 
 * Notes:
 * 
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 * Credits:
 * Special thanks to @stellari for adding this problem and creating all test cases.
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
    // WAY I: create a cycle and use slow and fast points to find the intersection node 
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;

        //  move List A to the end 
        ListNode *p = headA;
        while(p->next) p = p->next;

        // to create a cycle, link the last node with head A 
        p->next = headA;

        // determine if the link begining with B has a cycle
        ListNode *slow = headB;
        ListNode *fast = headB;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }

        ListNode *p1 = NULL;
        ListNode *p2;

        // slow point meets fast point, cycle exists, to find the intersection node
        if(slow->next != NULL && slow == fast) {
            p1 = slow;
            p2 = headB;
            while(p1 != p2) {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        
        // recover structure of Link A
        p->next = NULL;

        return p1;
    }

    // WAY II: 
    // *************************************************************************************
    // *
    // * When pA reaches the end of a list, then redirect it to the head of B (yes, B, that's right.); 
    // * similarly when pB reaches the end of a list, redirect it the head of A.
    // * If at any point pA meets pB, then pA/pB is the intersection node.
    // * If two lists have intersection, then their last nodes must be the same one.
    // * So when pA/pB reaches the end of a list, record the last element of A/B respectively.
    // * If the two last elements are not the same one, 
    // * then the two lists have no intersections.
    // *
    // **************************************************************************************
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode *pa = headA;
        ListNode *pb = headB;
        bool isAvisited = false;
        bool isBvisited = false;

        // iterate List A and List B one step at a time until pa meets pb
        while(pa != pb) {
            pa = pa->next;
            pb = pb->next;

            // when pa reaches the end of List A, move pa to List B
            if(pa == NULL) {
                // when pa reaches NULL at first time, set visited flag and redirect pb to List B
                if(!isAvisited) {
                    isAvisited = true;
                    pa = headB;
                }
                else
                    return NULL;
            }

            // when pb reaches the end of List B, move pb to List B
            if(pb == NULL) { 
                // when pb reaches NULL at first time, set visited flag and redirect pb to List A
                if(!isBvisited) {
                    isBvisited = true;
                    pb = headA;
                }
                else
                    return NULL;
            }
            
        }
            
        return pa;
    }
};

int main() {
    Solution slt;

    /******************************************
     *
     * A:          a1 → a2
     *                    ↘
     *                      c1 → c2 → c3
     *                    ↗            
     * B:     b1 → b2 → b3
     *
     ******************************************/
    ListNode *pa = new ListNode(1);
    ListNode *p = pa;
    p = p->next = new ListNode(3);

    ListNode *inter;
    p = inter = p->next = new ListNode(5);
    p = p->next = new ListNode(7);
    p = p->next = new ListNode(9);

    ListNode *pb = new ListNode(2);
    p = pb;
    p = p->next = new ListNode(4);
    p = p->next = new ListNode(6);
    //p->next = inter;

    p = slt.getIntersectionNode(pa, pb);

    if(p)
        DE(p->val);
    else
        cout << "No intersection " << endl;

    p = slt.getIntersectionNode(pa, pa);

    if(p)
        DE(p->val);
    else
        cout << "No intersection " << endl;

    return 0;
}






