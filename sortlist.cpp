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
	ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* temp;
        ListNode* aux = new ListNode(0);
        temp = aux;

        while ( b != NULL )
            if ( a == NULL )	{ a = b;  break; }
            else if ( b->val > a->val )
                { temp = temp->next = a; a = a->next; }
            else	
                { temp = temp->next = b; b = b->next; };

        temp->next = a;
        temp = aux->next;
        delete aux;

        return temp;
	}

    ListNode *sortList(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}

		// find the mid node, and split to two lists
		ListNode* p = head;
		ListNode* q = head;
		ListNode* pPre = p;
		while (q != NULL && q->next != NULL) {
			pPre = p;
			p = p->next;
			q = q->next->next;
		}
		pPre->next = NULL; // split

		// divide and conquer
		ListNode* l1 = sortList(head);
		ListNode* l2 = sortList(p);

		// merge
		return merge(l1, l2);
    }
};

int main() {
    Solution s;

    ListNode* head = new ListNode(100);
    head->next = new ListNode(50);
    head->next->next = NULL;
    head = s.sortList(head);
    ListNode* tmp = head;
    while(tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }

    cout << endl;
    return 0;
}
