/*******************************************************************************************
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*
*******************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* removeDuplicateLetters(char* s) {
    if (s == NULL) return NULL;

    static int  lastPos[26];
    static short  included[26];
    char *stash;
    int i, cnt, len;

    len = strlen(s);
    memset(included, 0, sizeof(included));

    for(i = 0; i < 26; i++)
       lastPos[i] = -1;

    for(cnt = 0, i = len-1; i >= 0; i--) {
       int num = s[i]-'a';
       if (lastPos[num] == -1) { // appear for the first time
          lastPos[num] = i;
          cnt++;
       }
    }
    stash = (char*)malloc(cnt+1);

    for(cnt = 0, i = 0; i < len; i++) {
       if (included[s[i]-'a'] == 0) {
           while(cnt > 0 && stash[cnt-1] > s[i] && lastPos[stash[cnt-1]-'a'] > i) {
               included[stash[cnt-1]-'a'] = 0;
               cnt--;
           }
           stash[cnt++] = s[i];
           included[s[i]-'a'] = 1;
           stash[cnt] = '\0';
       }
    }
    stash[cnt] = '\0';

    return stash;
}


int main() {

   char s1[] = "bcabc";
   char expected1[] = "abc";
   char *result1 = removeDuplicateLetters(s1);
   assert(strcmp(expected1, result1) == 0);
   printf("First case: OK\n");
   free(result1);

   char s2[] = "cbacdcbc";
   char expected2[] = "acdb";
   char *result2 = removeDuplicateLetters(s2);
   assert(strcmp(expected2, result2) == 0);
   printf("Second case: OK\n");
   free(result2);

   char s3[] = "thesqtitxyetpxloeevdeqifkz";
   char expected3[] = "hesitxyplovdqfkz";
   char *result3 = removeDuplicateLetters(s3);
   assert(strcmp(expected3, result3) == 0);
   printf("Second case: OK\n");
   free(result3);

   char s4[] = "mitnlruhznjfyzmtmfnstsxwktxlboxutbic";
   char expected4[] = "ilrhjfyzmnstwkboxuc";
   char *result4 = removeDuplicateLetters(s4);
   assert(strcmp(expected4, result4) == 0);
   printf("Second case: OK\n");
   free(result4);

   return 0;
}
