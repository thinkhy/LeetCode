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
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

    class Solution {
    public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            ListNode *aux = new ListNode(0);
            ListNode *tmp = aux;

            while(l2) {      
                if (l1 == NULL) {
                    l1 = l2;
                    break;
                }
                else if(l1->val < l2->val) {
                    tmp = tmp->next = l1;
                    l1 = l1->next;
                }
                else {
                    tmp = tmp->next= l2;
                    l2 = l2->next;
                }
            }

            tmp->next = l1;
            tmp = aux->next;
            delete aux;

            return tmp;
        }
    };

int main() {
    Solution s;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = NULL;

    ListNode* l2 = new ListNode(0);
    l2->next = new ListNode(2);
    l2->next->next = NULL;

    ListNode* head = s.mergeTwoLists(l1, l2);
    ListNode* tail = head;
    while(tail) {
        cout << tail->val << " ";
        tail = tail->next;
    }
    cout << endl;

    return 0;
}

