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
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;
   
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *aux = new ListNode(0);
        aux->next = head;

        ListNode *cur = head;
        ListNode *reverse_start;
        ListNode *reverse_end;
        ListNode *pre = aux;
        bool first_hit = true;
        int pos = 0;

        while(cur&&pos<n) {
            pos++;
            if(pos == m) {
                reverse_start = pre;
                reverse_end = cur;
                //DE(reverse_end->val);
                cur = cur->next;
                pos++;

                while(cur && pos <= n && pos > m) {
                    ListNode *tmp = cur->next;
                    cur->next = reverse_start->next;
                    reverse_start->next = cur;

                    cur = tmp;
                    pos++;
                }

            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        reverse_end->next = cur;
        
        ListNode *re = aux->next;
        delete aux;
        
        return re;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    for(int i = 2; i < 6; i++) 
        p = p->next = new ListNode(i);

    ListNode *re = s.reverseBetween(head, 2, 4);
    p = re;
    while(p) {
        //cout << p->val << " ";
        DE(p->val);
        p = p->next;
    }
    cout << endl;

    return 0;
}


