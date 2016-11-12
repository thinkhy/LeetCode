package main

import (
   "fmt"
   "testing"
)

func strStr(str string, t string) int {
  if len(t) == 0 {
    return -1
  }

  step := make([]int, len(t))
  step[0] = -1
  for i := 1; i < len(t); i++ {
    j := i-1
    for j != -1 {
       if t[step[j]+1] == t[i] {
	  break
       }
       j = step[j]
    }
    if j == -1 {
	 step[i] = -1
    } else {
         step[i] = step[j]+1
    }
  }
  fmt.Println(step)

  var i, j int
  for i,j = 0, 0; i < len(str); {
    for i < len(str) && j < len(t) {
       fmt.Printf("[i: %d, j: %d]\n", i, j)
       if str[i] == t[j] {
          i++
	  j++
       } else if j > 0 {
          j = step[j-1]+1
       } else {
          break
       }
    }
    fmt.Printf(">>[i: %d, j: %d]\n", i, j)

    // not matched at current position
    if j == 0 {
       i++
    } else if j == len(t) {
      return i-len(t)
    } else {
      return -1
    }
  }

  return -1
}

func TestMain(t *testing.T) {
/*
  result := strStr(d.s, d.target)
  fmt.Printf("Expected %d, got %d\n", d.expect, result)
  if result != d.expect {
     t.Fatalf("Expected %d, got %d\n", d.expect, result)
  }
*/
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList_withAdditionalHeadNode(head *ListNode) *ListNode {
  if head == nil {
      return nil
  }
  hh := new(ListNode)
  hh.Next = head
  p := head.Next
  head.Next = nil
  var q *ListNode

  for p != nil {
     q = p.Next
     p.Next = hh.Next
     hh.Next = p
     p = q
  }

  return hh.Next
}

func reverseList(head *ListNode) *ListNode {
   var prev *ListNode = nil
   cur := head
   for cur != nil {
     tmp := cur->Next
     cur->Next = prev
     prev = cur
     cur = tmp
   }

   return prev
}

func reverseList_recursive(head *ListNode) *ListNode {
  if head == nil {
    return nil
  }

  if head->Next == nil {
    return head
  }

  newHead := reverseList(head->Next)
  head->Next->Next = head
  head->Next = nil
  return newHead
}



func main() {
  tt := new(testing.T)
  TestMain(tt)
}


