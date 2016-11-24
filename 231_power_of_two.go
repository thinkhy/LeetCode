package main
import (
   "fmt"
)
/**************************************************************************
 *
 * Given an integer, write a function to determine if it is a power of two.
 *
 **************************************************************************/

func isPowerOfTwo(n int) bool {
  if (n < 1) return false
  if (n == 1) return true
  if (n % 2 !== 0) return false 
  return isPowerOfTwo(n/2);
}

func isPowerOfTwo(n int) bool {
  if (n<=0) { return false }
  return n&(n-1) == 0
}

func main() {
}
