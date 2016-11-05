package main
/****************************************************************
 Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

 You may assume that each input would have exactly one solution.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2
 ****************************************************************/
import "fmt"

func twoSum_hash(numbers []int, target int) []int {
  if len(numbers) < 2 {
    return nil
  }
  var m map[int]int
  m = make(map[int]int)
  for i := 0; i < len(numbers); i++{
    if j, present := m[target-numbers[i]]; present && i!=j  {
      return []int{j+1, i+1}
    }
    m[numbers[i]] = i
  }
  return nil
}

func twoSum(numbers []int, target int) []int {
  if len(numbers) < 2 {
    return nil
  }
  low := 0
  high := len(numbers) - 1
  for ; low < high; {
     s := numbers[low] + numbers[high]
     if s < target {
       low++
     } else if s > target {
       high--
     } else {
       return []int{low+1, high+1}
     }
  }
  return nil
}

func main(){
  nums := []int{0, 0, 3, 4}
  target := 0
  res := twoSum(nums, target)
  fmt.Print(res)
}


