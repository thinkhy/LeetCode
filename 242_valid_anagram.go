package main
/***********************************************************************************

 Given two strings s and t, write a function to determine if t is an anagram of s.

 For example,
 s = "anagram", t = "nagaram", return true.
 s = "rat", t = "car", return false.

 Note:
 You may assume the string contains only lowercase alphabets.

 Follow up:
 What if the inputs contain unicode characters? How would you adapt your solution to such case?

 ***********************************************************************************/
import (
   "fmt"
)

func isAnagram(s string, t string) bool {
    cnt := [26]int{}
    for i := 0; i < len(s); i++ {
       cnt[s[i]-'a']++
    }
    for i := 0; i < len(t); i++ {
       cnt[t[i]-'a']--
       if cnt[t[i]-'a'] < 0 {
          return false
       }
    }
    for i := 0; i < 26; i++ {
      if cnt[i] != 0 {
         return false
      }
    }
    return true
}

func main() {
  s1 := "anagram" 
  t1 := "nagaram"
  fmt.Print("Case1: ", true==isAnagram(s1, t1), "\n")

  s2 := "rat" 
  t2 := "car"
  fmt.Print("Case2: ", false==isAnagram(s2, t2), "\n")
  
  s3 := "ab" 
  t3 := "a"
  fmt.Print("Case3: ", false==isAnagram(s3, t3), "\n")
}
