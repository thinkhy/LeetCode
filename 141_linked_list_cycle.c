#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
   int val;
   struct ListNode *next;
};
typedef struct ListNode *P;
typedef int bool;
#define false 0
#define true  1

bool hasCycle(struct ListNode *head) {
   if (head == NULL) {
      return false;
   }
   if (head->next == NULL) {
     return false;
   }
   P slow, fast;
   slow = head->next;
   fast = head->next->next;
   printf("%d\n", head->val);
   while (fast != NULL) {
   printf("%d\n", slow->val);
   printf("%d\n", fast->val);
     if (slow == fast) return true;
     slow = slow->next;
     if (fast->next == NULL) return false;
     fast = fast->next->next;
   }

   return false;
}

int main() {
   P head = (P)malloc(sizeof(struct ListNode));
   P next = (P)malloc(sizeof(struct ListNode));
   head->val = 2;
   next->val = 3;
   head->next = next;
   next->next = head;
   printf("result: %d\n", hasCycle(head));
}



