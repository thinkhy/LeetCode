package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSameTree(p *TreeNode, q *TreeNode) bool {
   if p == q {
     return true
   }
   if (p == nil || q == nil) {
     return false
   }

   if p.Val == q.Val &&
      isSameTree(p.Left, q.Left) &&
      isSameTree(p.Right, q.Right) {
     return true
   }

   return false
}
