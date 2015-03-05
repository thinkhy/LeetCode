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
#include <cstdlib>
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
            ListNode *insertionSortList(ListNode *head) {
                  if(head == NULL || head->next == NULL)
                      return head;

                  ListNode *p, *ppre, *tmp;
                  ListNode *q = head->next;
                  head->next = NULL;

                  while (q) {      
                     ppre=NULL;
                     p = head;
                     while(p != NULL && p->val <= q->val) {
                        ppre = p;
                        p = p->next;
                     }

                     tmp = q->next;

                     if (ppre)
                         ppre->next = q;
                     else
                         head=q;

                     q->next=p;

                     q=tmp;
                  }

                  return head;
            }
        };

int main() {
    //seed(time(NULL));
    Solution s;
    ListNode *head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = NULL;
    ListNode *tail = head;
    for (int i = 0; i < 11; i++) {
        tail = tail->next = new ListNode(rand()%100);
    }
    tail->next = NULL;

    tail = s.insertionSortList(head);
    while(tail) {
        cout << tail->val << " "; 
        tail = tail->next;
    }

    return 0;
}

