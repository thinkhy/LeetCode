package main

//import "fmt"
/**************************************************
 * 
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along
 * the longest path from the root node down to the 
 * farthest leaf node.
 * 
 **************************************************/

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

func maxDepth(root *TreeNode) int {
   max := 0
   curLen := 0
   top := 0
   cur := root
   stack := make([]*TreeNode, 1000)
   if cur != nil {
     stack[top] = cur
     cur.Val = 1
     top++
   }

   for top > 0 {
     // stack pop elem
     cur = stack[top-1]
     top--
     curLen = cur.Val

     if curLen > max {
       max = curLen
     }

     if cur.Right != nil {
         stack[top] = cur.Right
         top++
         cur.Right.Val = curLen + 1
     }
     if cur.Left != nil {
         stack[top] = cur.Left
         top++
         cur.Left.Val = curLen + 1
     }
   }
   return max
}

func maxDepthi_recursive(root *TreeNode) int {
   if root == nil {
     return 0
   }
   l := maxDepth(root.Left)
   r := maxDepth(root.Right)
   if l > r {
      return l + 1
   } else {
      return r + 1
   }
}

func main() {
  root := new(TreeNode)
  root.Val = 1
  root.Right = nil
  root.Left = new(TreeNode)
  root.Left.Val = 2
  root.Left.Right = nil
  root.Left.Left = nil
  println(maxDepth(root))
}

