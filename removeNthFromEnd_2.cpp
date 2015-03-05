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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL)
            return NULL;

        ListNode *aux = new ListNode(0);
        aux->next = head;
        ListNode *first = head;
        ListNode *second = aux;
        for(int i = 0; i < n; i++) 
            first = first->next;

        while(first) {
            first = first->next;
            second = second->next;
        }

        if(second->next)
            second->next = second->next->next;

        head  = aux->next;
        delete aux;

        return head;
    }
};

int main() {
    Solution s;
    ListNode *head;
    int n;

    ListNode *p = head;
    ListNode *pre = NULL;
    for(int i = 0; i < 5; i++) {
        p = new ListNode(i+1);
        if(pre)
            pre->next = p;
        else
            head = p;
        pre = p;
    }

    p = s.removeNthFromEnd(head, 2);
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    p = s.removeNthFromEnd(head, 0);
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    p = s.removeNthFromEnd(head, 1);
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    p = s.removeNthFromEnd(head, 3);
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}


