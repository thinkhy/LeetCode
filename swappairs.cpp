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
    ListNode *swapPairs(ListNode *head) {
       if(head == NULL) return NULL;
       ListNode *p = head;
       ListNode *q, *pre;
       ListNode *aux = new ListNode(-1);
       aux->next = head;
       pre = aux;


       while (p && p->next) {
          pre->next = p->next;
          q = p->next->next;
          p->next->next = p;
          p->next = q;
          pre = p;
          p=p->next;
       }

       q = aux->next;
       delete aux;

       return q;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);

    head = s.swapPairs(head);
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    head = new ListNode(1);
    head->next = new ListNode(2);

    head = s.swapPairs(head);
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    head = s.swapPairs(head);
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    head = s.swapPairs(head);
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}

