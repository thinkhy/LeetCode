package main

/**
 *
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 *
 */

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
   head := new(ListNode)
   head.Next = nil

   prev := head
   for l1 != nil && l2 != nil {
      if l1.Val <= l2.Val {
         prev.Next = l1
	 prev = l1
	 l1 = l1.Next
      } else {
         prev.Next = l2
	 prev = l2
	 l2 = l2.Next
      }
   }

   // deal with remaining nodes
   if l1 != nil {
      prev.Next = l1
   } else {
      prev.Next = l2
   }

   return head.Next
}

func main() {
}
