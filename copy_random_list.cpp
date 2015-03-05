#include <iostream>
#include <string>
#include <sstream>
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
#include <iterator>
#include <cstdio>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;


/*
   A linked list is given such that each node contains an additional random pointer 
   which could point to any node in the list or null. Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
  int label;
  RandomListNode *next, *random;

  RandomListNode(int x) : label(x), next(NULL), random(NULL) 
  {
  }
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        RandomListNode *dup_head = new RandomListNode(head->label);              
        dup_head->random = head->random;

        unordered_map<RandomListNode*, RandomListNode*> listNodeMap;
        listNodeMap[head] = dup_head;
        RandomListNode *p, *q;
        p = head->next;
        q = dup_head;

        while(p) {
            q->next = new RandomListNode(p->label);              
            q = q->next;
            listNodeMap[p] = q;
            q->random = p->random;
            p = p->next;
        }

        q = dup_head;
        while(q) {
            q->random = q->random ? listNodeMap[q->random] : NULL;
            q = q->next;
        }
        
        return dup_head;
    }
};


int main() {
    Solution s;
    
    RandomListNode *root = new RandomListNode(-1);
    RandomListNode *p = root;
    p = p->next = new RandomListNode(1);
    root->random = p;
    p->random = p;

    p = s.copyRandomList(root);
    while(p) {
        cout << p->label << ": " << (p->random ? p->random->label : NULL) << endl;
        p = p->next;
    }

    return 0;
}








