package main

/***********************************************************************************************
 
 Implement strStr().

 Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 **********************************************************************************************/
import (
  "fmt"
)

func strStr(str string, t string) int {
   if (len(str) == 0 || len(t) == 0) {
     return -1
   }

   for i := 0; i < len(str); i++ { 
     j := 0
     for ; i+j<len(str) && j<len(t) && str[i+j]==t[j]; j++ {}
     if j == len(t) {
       return i
     }
   }
   return -1
}

func main() {
  s1 := "abccss"
  t := "css"
  fmt.Print("case1: ", (strStr(s1, t) == 3), "\n")

  s1 = "abccss"
  t = ""
  fmt.Print("case1: ", (strStr(s1, t) == -1), "\n")

  s1 = ""
  t = "abc"
  fmt.Print("case1: ", (strStr(s1, t) == -1), "\n")

  s1 = "a"
  t = "abc2"
  fmt.Print("case1: ", (strStr(s1, t) == -1), "\n")

  s1 = ""
  t = ""
  fmt.Print("case1: ", (strStr(s1, t) == -1), "\n")
}
