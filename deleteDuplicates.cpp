#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL) return NULL;

        ListNode *aux = new ListNode(0);
        aux->next = head;
        ListNode *pre = aux;
        int lastval, cnt;
        ListNode *p = head;
        ListNode *q;

        while(p) {
            lastval = p->val;
            q = p;
            p = p->next; 

            while(p && p->val == lastval) 
                p = p->next;
            if(p == q->next) {
                pre->next = q;
                pre = q;
            }
            else  {
                pre->next = q;
                pre = q->next;
            }
        }

        if(pre) pre->next = NULL;

        ListNode *r = aux->next;
        delete(aux);
        
        return r;
    }
};

int main() {
    Solution s;    

    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    ListNode *p;
    p = head->next->next = new ListNode(1);
    p = p->next = new ListNode(2);
    p = p->next = new ListNode(2);
    p = p->next = new ListNode(4);
    p = p->next = new ListNode(4);
    p = p->next = new ListNode(5);

    p = s.deleteDuplicates(head);
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}






