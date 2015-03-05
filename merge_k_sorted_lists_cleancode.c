#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    struct ListNode *next;
};

struct ListNode *mergeKLists(struct ListNode *lists[], int k) {
    typedef struct ListNode LN;
    LN *head = NULL;

    // allocat an array for min heap
    LN *heap_array = (LN*)malloc(k*sizeof(LN));   

    // insert nodes to heap from sorted lists

    return NULL;
}

void print(int a[], int n) {
    int i;
    for(i = 0; i < n; i++)  
        printf("%d ", a[i]);
    printf("\n");
}

LN* makeNode(int val) {
    LN *p = (LN*)malloc(sizeof(LN));
    p->val = val;
    return p;
}

int main() {
    LN* lists[10];
    LN *p;
    LN *pa = makeNode(2);
    p = pa;
    p = p->next = makeNode(5);
    p = p->next = makeNode(8);
    p = p->next = makeNode(11);

    LN *pb = makeNode(4);
    p = pb;
    p = p->next = makeNode(7);
    p = p->next = makeNode(10);

    LN *pc = makeNode(3);
    p = pc;
    p = p->next = makeNode(6);
    p = p->next = makeNode(9);
    p = p->next = makeNode(12);

    lists[0] = pa;
    lists[1] = pb;
    lists[2] = pc;

    p = mergeKLists(lists, 3);
    while(p) {
        printf("%d ", p->val);
        p = p->next;
    }

    return 0;
}


