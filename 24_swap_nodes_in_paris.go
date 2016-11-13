package main

/*****
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 *
 */

/**
 * Definition for singly-linked list.
 **/
type ListNode struct {
	Val int
	Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
    var hh *ListNode
    tail := &hh
    cur := head

    for cur != nil && cur.Next != nil {
       *tail = cur.Next
       tail = &(cur.Next)

       tmp := cur.Next.Next
       cur.Next.Next = cur
       cur = tmp
    }

    if cur != nil {
      *tail = cur
    } else {
      *tail = nil
    }

    return hh
}

/*
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 *
 */
func main() {
   head := new(ListNode)
   head.Val = 1
   prev := head
   for i := 2; i <= 6; i++ {
      prev.Next = new(ListNode)
      prev.Next.Val = i
      prev = prev.Next
   }

   h := swapPairs(head)
   for h != nil {
      println(h.Val)
      h = h.Next
   }
}


