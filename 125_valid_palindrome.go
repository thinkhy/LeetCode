package main

/****************************************************************
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

Subscribe to see which companies asked this question

Hide Tags Two Pointers String

 ****************************************************************/
import (
    "fmt"
    "strings"
    )

func isPalindrome(s string) bool {
	i := 0
	j := len(s) - 1
	s = strings.ToUpper(s)
	for ; i < j; i, j = i+1, j-1 {
		for (s[i] > 'Z' || s[i] < 'A') &&
			(s[i] > 'z' || s[i] < 'a') &&
			(s[i] > '9' || s[i] < '0') &&
			i < j {
			i++
		}
		for (s[j] > 'Z' || s[j] < 'A') &&
			(s[j] > 'z' || s[j] < 'a') &&
			(s[j] > '9' || s[j] < '0') &&
			i < j {
			j--
		}
		if s[i] != s[j] {
			return false
		}
	}
	return true
}

func main() {
	s := `A man, a plan, a canal: Panama`
	fmt.Print(s, ": ", isPalindrome(s), "\n")
	s = `race a car`
	fmt.Print(s, ": ", isPalindrome(s), "\n")
	s = ``
	fmt.Print(s, ": ", isPalindrome(s), "\n")
	s = `a`
	fmt.Print(s, ": ", isPalindrome(s), "\n")
	s = `ab`
	fmt.Print(s, ": ", isPalindrome(s), "\n")
	s = `0P`
	fmt.Print(s, ": ", isPalindrome(s), "\n")
}
