package main
/****************************************************************
 Rotate an array of n elements to the right by k steps.

 For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

 Note:
 Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

 [show hint]

 Hint:
 Could you do it in-place with O(1) extra space?
 Related problem: Reverse Words in a String II

 Credits:
 Special thanks to @Freezen for adding this problem and creating all test cases.

 Subscribe to see which companies asked this question
 ****************************************************************/
import "fmt"

func rotate(nums []int, k int) {
   k = k % len(nums)
   l := len(nums)
   copy(nums, append(nums[l-k:], nums[:l-k]...))
}

func main(){
  nums := []int{1,2,3,4,5,6,7}
  k := 3
  rotate(nums, k)
  fmt.Print(nums)
}


