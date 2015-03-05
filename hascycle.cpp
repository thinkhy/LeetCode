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
    bool hasCycle(ListNode *head) {
       ListNode *p1 = head;
       ListNode *p2 = head;;
       while(p1&&p2&&p2->next) { 
           p1=p1->next;
           p2=p2->next->next;
           if(p1 == p2) 
               return true;
       }
       return false;
    }
};
int main() {
    Solution s;
    ListNode *head = new ListNode(3);
    ListNode *p = head->next = new ListNode(2);
    ListNode *tmp = p;
    p = p->next = new ListNode(0);
    p = p->next = new ListNode(-4);
    p->next = tmp;
    cout << s.hasCycle(head) << endl;
}
