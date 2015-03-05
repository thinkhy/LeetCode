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

        vector<ListNode*> elems;
        ListNode *p = head;
        while(p) {
            elems.push_back(p);
            p = p->next;
        }

        p = elems[elems.size()-n];
        if(p == head)
            head = head->next;
        else {
            elems[elems.size()-n-1]->next = p->next;
        }

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

    return 0;
}


