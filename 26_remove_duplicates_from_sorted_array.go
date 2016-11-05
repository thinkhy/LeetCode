package main
/****************************************************************
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

 Do not allocate extra space for another array, you must do this in place with constant memory.

 For example,
 Given input array nums = [1,1,2],

 Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

 Subscribe to see which companies asked this question
 ****************************************************************/
import "fmt"

func removeDuplicates(nums []int) int {
   if (len(nums) == 0) {
   	return 0
   }
   i := 0
   for j := 1; j < len(nums); {
       if nums[i] == nums[j] {
       	     j = j + 1
       } else {
          i = i + 1
          nums[i] = nums[j]
	  j = j + 1
       }
   }
   return i+1
}

func main(){
  nums := []int{1, 1, 2}
  ss := removeDuplicates(nums)
  fmt.Printf("Size: %d\nNums: ", ss)
  for i := 0; i < ss; i++ {
     fmt.Printf("%d\t", nums[i])
  }
  fmt.Printf("\n")
}


