package main
/**********************************************************************
 Implement atoi to convert a string to an integer.

 Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

 Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
 The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

 spoilers alert... click to show requirements for atoi.

 **********************************************************************/

import (
  "fmt"
)

func myAtoi(str string) int {
   res := 0
   flag := 1
   isNum := false
   for i := 0; i < len(str); i++ {
     if str[i] <= '9' && str[i] >= '0' {
        isNum = true
	res = res * 10 + int(str[i]-'0')
     } else if !isNum {
        if str[i] == '-' || str[i] == '+' {
		isNum = true
		if str[i] == '-' {
			flag = -1 
		} else {
			flag = 1 
		}
	} else if str[i] == ' ' {
	   continue
	}
     } else {
        break
     }
   }
   return flag*res
}

func main() {
  s := "1234"
  fmt.Print("case 1: ", (myAtoi(s) == 1234), "\n")
  fmt.Print("case 1: ", (myAtoi("") == 0), "\n")
  fmt.Print("case 1: ", (myAtoi("01230") == 1230), "\n")
  fmt.Print("case 1: ", myAtoi("+"), " ", (myAtoi("+") == 0), "\n")
  fmt.Print("case 1: ", (myAtoi("-1") == -1), "\n")
  fmt.Print("case 1: ", (myAtoi("+-1") == 0), "\n")
  fmt.Print("case 1: ", (myAtoi("    010") == 10), "\n")
  fmt.Print("case 1: ", (myAtoi(" -0012a42") == -12), "\n")
}
