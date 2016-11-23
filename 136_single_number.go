package main
import ( 
  "fmt"
)
/*******************************************************************
  
 Given an array of integers, every element appears twice except for one.
 Find that single one.

 Note:
  Your algorithm should have a linear runtime complexity.
  Could you implement it without using extra memory?

 *******************************************************************/
func singleNumber(nums []int) int {
   s := 0
   for _, n := range nums {
       s ^= n
   }
   return s
}

func main() {
  nums := []int{1,1,2}
  fmt.Println(singleNumber(nums))
  nums = []int{1}
  fmt.Println(singleNumber(nums))
  nums = []int{}
  fmt.Println(singleNumber(nums))
}
