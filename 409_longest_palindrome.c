/*******************************************************************************************************
 Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

 This is case sensitive, for example "Aa" is not considered a palindrome here.

 Note:
   Assume the length of given string will not exceed 1,010.

 Example:

 Input:
   "abccccdd"

 Output:
   7

 Explanation:
   One longest palindrome that can be built is "dccaccd", whose length is 7.
 ******************************************************************************************************/
#include <stdio.h>
#include <string.h>

int longestPalindrome(char* s) {
   #define MAX(x,y)  (x)>(y)?(x):(y)
   if (s == NULL) return 0;
   int p[1010][1010] = {0};
   int i, j;
   int len = strlen(s);
   for (i = 0; i < len; i++) {
     p[i][i] = 1;
   }
   for (i = 2; i <= len; i++) {
     for (j = 0; j <= len-i; j++) { 
        p[j][j+i-1] = MAX(p[j+1][j+i-1], p[j][j+i-2]); 
	if (s[j] == s[j+i-1] && p[j+1][j+i-2] == i-2) {
	    p[j][j+i-1] = p[j+1][j+i-2] + 2;
	}
     }
   }
   return p[0][len-1];
}

int main() {
  char *s1 = "aaaaaaaaaaAAAAAaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; 
  if (longestPalindrome(s1) == 500)
      printf("case1: OK\n");
  else 
      printf("case1: Failed\n");
  char *s2 = "bbbaaaa"; 
  if (longestPalindrome(s2) == 4)
      printf("case2: OK\n");
  else 
      printf("case2: Failed\n");
  char *s3 = "abcccdd"; 
  if (longestPalindrome(s3) == 3)
      printf("case3: OK\n");
  else 
      printf("case3: Failed\n");
  return 0;
}

