#include <iostream>
#include <string>
#include <sstream>
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
#include <iterator>
#include <cstdio>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/* 
 * Add Two Numbers
 *
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *aux = new ListNode(-1);
/*
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 */
        ListNode *p=aux;
        int carry = 0;
        int sum;
        while(l1 != l2) {
            sum = carry; 
            if(l1 == NULL) {
                sum += l2->val; 
                l2=l2->next;
             }
             else if(l2 == NULL) {
                sum += l1->val;
                l1=l1->next;
             }
             else {
                sum += l1->val + l2->val;
                l1=l1->next;
                l2=l2->next;
             }
            
             p = p->next = new ListNode(sum%10);
             carry = sum/10;
        }
        if(carry)
            p = p->next = new ListNode(carry);

        ListNode *re = aux->next;
        delete aux;
        
        return re;
    }
};

int main() {
    Solution s;

    ListNode *re;
    ListNode *l1, *l2, *p;

    l1 = p = new ListNode(2);
    p = p->next = new ListNode(4);
    p = p->next = new ListNode(3);

    l2 = p = new ListNode(5);
    p = p->next = new ListNode(6);
    p = p->next = new ListNode(9);

    p = s.addTwoNumbers(l1, l2);
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
     
    return 0;
}








