package main
/**************************************************************
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.

Example 2:
    1
   / \
  2   3

Binary tree [1,2,3], return false. 

 **************************************************************/

import (
  "fmt"
)

type TreeNode struct {
   Val int
   Left *TreeNode
   Right *TreeNode
}

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
  if (root == nil) {
    return true
  }
  var prev *TreeNode
  return inorderTraver(root, &prev)
}

func inorderTraver(root *TreeNode, prev **TreeNode) bool {
  if root == nil {
    return true
  }
  res := inorderTraver(root.Left, prev)
  if res == false {
    return res
  }
  if (*prev != nil) {
    if (*prev).Val >= root.Val {
        return false
    }
  }
  *prev = root
  res = inorderTraver(root.Right, prev)
  return res
}

func main() {
   fmt.Println("Hello")
/**************************************
    2
   / \
  1   3
  Binary tree [2,1,3], return true.
 **************************************/
 root := new(TreeNode)
 root.Val = 1
 root.Left = new(TreeNode)
 root.Right = nil
 root.Left.Val = 1
 root.Left.Left = nil
 root.Left.Right = nil
 fmt.Println(isValidBST(root))
}


