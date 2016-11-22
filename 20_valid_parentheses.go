package main

/*****************************************************************

 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

 Subscribe to see which companies asked this question

 *****************************************************************/
import (
  "fmt"
)


func isValid(s string) bool {
   stack := []byte{}
   for i := 0; i < len(s); i++ {
       if s[i] == '(' ||
	  s[i] == '[' ||
	  s[i] == '{' {
	  stack = append(stack, s[i])
       } else {
       	  e := len(stack)-1
          if (e < 0 ||
	     (stack[e] == '(' && s[i] != ')') ||
             (stack[e] == '[' && s[i] != ']') ||
             (stack[e] == '{' && s[i] != '}') ) {
	     return false
	  } else {
	     stack = stack[:e]
	  }
       }
   }
   return len(stack) == 0
}

func main() {
   fmt.Println(true == isValid("()"))
   fmt.Println(true == isValid(""))
   fmt.Println(true == isValid("()[]{}"))
   fmt.Println(true == isValid("(]"))
   fmt.Println(true == isValid("([)]"))
   fmt.Println(true == isValid("("))
}
