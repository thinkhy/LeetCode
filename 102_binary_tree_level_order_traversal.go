package main
import (
   "fmt"
)
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func levelOrder(root *TreeNode) [][]int {
  res := [][]int{}
  if root == nil {
     return res
  }
  var q []*TreeNode
  level := 1
  q = append(q, root)

  for (len(q) > 0) {
    next := 0
    same_level := []int{}
    for i := 0; i < level; i++ {
        cur := q[0]
        q = q[1:]
	same_level = append(same_level, cur.Val)
	if cur.Left != nil {
	    next++
            q = append(q, cur.Left)
	}
	if cur.Right != nil {
	    next++
            q = append(q, cur.Right)
	}
    }
    level = next
    res = append(res, same_level)
  }

  return res
}

func main() {
   root := new(TreeNode);
   root.Val = 3

   root.Left = new(TreeNode);
   root.Left.Val = 9;
   root.Left.Left = nil;
   root.Left.Right = nil;

   root.Right = new(TreeNode);
   root.Right.Val = 20;
   root.Right.Left = new(TreeNode);
   root.Right.Left.Val = 15;
   root.Right.Left.Left = nil;
   root.Right.Left.Right = nil;

   root.Right.Right = new(TreeNode);
   root.Right.Right.Val = 7;
   root.Right.Right.Left = nil;
   root.Right.Right.Right = nil;

   res := levelOrder(root)
   for _, r := range res {
      for _, s := range r {
         fmt.Print(s, " ")
      }
      fmt.Print("\n")
   }
   return; 
}


