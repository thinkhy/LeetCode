package main
/**
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
**/

/**
 * 
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 * 
 */
type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func hasPathSum_iterative(root *TreeNode, sum int) bool {
  if root == nil { 
     return false
  }
  stack := []*TreeNode{}
  nums := []int{}

  stack = append(stack, root)
  nums = append(nums, root.Val)
  for len(stack) > 0 {
     // stack pop up
     l := len(stack) 
     cur, num := stack[l-1], nums[l-1]
     stack, nums = stack[:l-1], nums[:l-1]

     // leaf node
     if cur.Left == nil && cur.Right == nil {
        if num == sum {
           return true
        }
     } else { // immediate node
       if cur.Right != nil {
	  stack = append(stack, cur.Right)
	  nums = append(nums, num+cur.Right.Val)
       }
       if cur.Left != nil {
	  stack = append(stack, cur.Left)
	  nums = append(nums, num+cur.Left.Val)
       }
     }
  }
  return false
}


func hasPathSum(root *TreeNode, sum int) bool {
  if root == nil {
    return false // empty node shouldn't get ZERO value??
  }
  if root.Left == nil && root.Right == nil {
    return  (sum == root.Val)
  }

  if (root.Left != nil && hasPathSum(root.Left, sum - root.Val)) ||
      (root.Right != nil && hasPathSum(root.Right, sum - root.Val)) {
     return true
  }

  return false
}

func main() {

}


