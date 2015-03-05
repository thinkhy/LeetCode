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
#include <cstring>
using namespace std;


#define DE(a) cout << #a << ": " << a << endl;

/*
 * Merge k Sorted Lists 
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 */

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
    ListNode* merge_two(ListNode *la, ListNode *lb) {
        ListNode *aux = new ListNode(0);
        ListNode *p = aux;
     
        while(la) {
            if(lb && la->val > lb->val) {
                p = p->next = lb;
                lb = lb->next;
            }
            else {
                p = p->next = la;
                la = la->next;
            }
        }
        while(lb) {
            p = p->next = lb;
            lb = lb->next;
        }
     
        ListNode *ret = aux->next;
        delete aux;

        return ret;
    }

    ListNode *merge_k_lists(vector<ListNode *> &lists, int begin, int end) {
        int size = end - begin;

        if(size <= 0)
            return NULL;
        else if(size == 1) 
            return lists[begin];
        else if(size == 2) { // two lists, merge them directly
            return merge_two(lists[begin], lists[begin+1]);
        }
        else {               // more than one lists in the vector
            return merge_two(merge_k_lists(lists, begin, begin+size/2),
                             merge_k_lists(lists, begin+size/2, end));
        }
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return merge_k_lists(lists, 0, lists.size());
    }
};


void print(int a[], int n) {
    for(int i = 0; i < n; i++)  
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    Solution s;

    vector<ListNode*> lists;
    ListNode *p;
    ListNode *pa = new ListNode(2);
    p = pa;
    p = p->next = new ListNode(5);
    p = p->next = new ListNode(8);
    p = p->next = new ListNode(11);

    ListNode *pb = new ListNode(4);
    p = pb;
    p = p->next = new ListNode(7);
    p = p->next = new ListNode(10);

    ListNode *pc = new ListNode(3);
    p = pc;
    p = p->next = new ListNode(6);
    p = p->next = new ListNode(9);
    p = p->next = new ListNode(12);

    lists.push_back(pa);
    lists.push_back(pb);
    lists.push_back(pc);

    p = s.mergeKLists(lists);
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }

    return 0;
}


