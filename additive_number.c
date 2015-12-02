/************************************************************
 * Additive Number
 * https://leetcode.com/problems/additive-number/
 *
 * 2015-12-01 thinkhy
 *
 ***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* add_two_number(char *first, char *second) {
   int len1 = strlen(first);
   int len2 = strlen(second);
   int i,j,s,k;
   char *sum = malloc(len1+len2+1);
   int carry = 0;

   for(k = 0, i = len1-1, j = len2-1; i>=0 || j>=0; i--, j--, k++) {
       s = (i>=0 ? first[i]-'0' : 0) + (j>=0 ? second[j]-'0' : 0) + carry;
       sum[k] = s%10 + '0';
       carry = s/10;
   }

   if (carry != 0)
     sum[k++] = carry + '0';
   sum[k] = '\0';

   // shrink memory
   realloc(sum, k+1);

   // reverse string of sum
   for (i = 0, j = k-1; i < j; i++, j--) {
      sum[i] = sum[i] ^ sum[j];
      sum[j] = sum[i] ^ sum[j];
      sum[i] = sum[j] ^ sum[i];
   }


   return sum;
}

bool isAdditiveNumber(char* num) {
   int len = strlen(num);
   int len_sum;
   int i,j,k,h;
   bool ret = false;
   char *first, *second, *sum;
   first = second = sum = NULL;

   for(i = 0; i < len/2; i++) {
     first = (char*)malloc(i+1+1);
     strncpy(first, num, i+1);
     first[i+1] = '\0';

     for(j = i+1; j <= len/2; j++) {
       second = (char*)malloc(j-i+1);
       strncpy(second, num+i+1, j-i);
       second[j-i+1] = '\0';

       // the length of left string is enough, so traverse left string to detect if additive number exists
       h = j+1;  // h is the starting position of third number
       char *first2 = first;
       bool flag = false;;

       do {
            sum = add_two_number(first2, second);
            len_sum = strlen(sum);

            // printf("first: %s\n", first2);
            // printf("second: %s\n", second);
            // printf("sum: %s\n", sum);

            if (first2 != first) free(first2);
            first2 = second;
            second = sum;

            // obviously left string will not match sum
            if(len_sum > len - h)
                break;

           // if sum matches left string?
           for(k = 0; k < len_sum && sum[k] == num[h+k]; k++);
           if (k < len_sum)
               break;

           // left string matches, move forward
           flag = true;
           h = h + len_sum;
       } while (h < len);

       free(second);

       // find the solution, return true
       if (h == len)
            return flag;
     } // for j ...

     free(first);
  } // for i ...

  return false;
}


int main() {
  char s0[] = "123";
  printf("%s : %d\n", s0, isAdditiveNumber(s0));

  char s[] = "112358";
  printf("%s : %d\n", s, isAdditiveNumber(s));

  char s1[] = "198019823962";
  printf("%s : %d\n", s1, isAdditiveNumber(s1));

  char s2[] = "10";
  printf("%s : %d\n", s2, isAdditiveNumber(s2));

  return 0;
}


