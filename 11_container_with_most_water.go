package main
/*********************************************************************************************
 Given n non-negative integers a1, a2, ..., an,
 where each represents a point at coordinate (i, ai).
 n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 Find two lines, which together with x-axis forms a container,
 such that the container contains the most water.

 Note: You may not slant the container.
 *********************************************************************************************/
import "fmt"

func max(x, y int) int {
  if x > y {
     return x
  }

  return y
}

func min(x, y int) int {
  if x < y {
     return x
  }

  return y
}

func maxArea(h []int) int {
  m := 0
  for i,j := 0, len(h)-1; i < j; {
     m = max(m, (j-i)*min(h[j],h[i]))
     if (h[i] > h[j]) {
         j--;
     } else {
         i++;
     }
  }
  return m
}

func main() {
    //c1 := []int{5,4,3,2,1,5}
    c1 := []int{1,2,4,3}
    fmt.Print("Result: ", maxArea(c1), "\n")
}




