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

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       ListNode *p = head; 
       unordered_set<ListNode*> visited; 
       
       while(p&&visited.find(p) == visited.end()) {
            visited.insert(p);
            p = p->next;
       }

       return p;
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



