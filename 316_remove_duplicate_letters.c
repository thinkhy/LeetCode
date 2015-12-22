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

    static int  dic[26];
    static int  pos[26];
    int i, j, cnt, top, len;
    char *result;
    memset(dic, 0, sizeof(dic)/sizeof(*dic));
    memset(dic, 0xFF, sizeof(pos)/sizeof(*pos));
    len = strlen(s);
    top = 0;

    result = (char*)malloc(len+1);
    
    for(i = 0; i < strlen(s); i++) {
       int num = s[i]-'a';
       dic[num]++;   
       if (dic[num] == 1) { // appear for the first time
          pos[num] = i;
       }
       else {
          if (pos[num]++;
       }
    }

    for(cnt = 0, i = 0; i < strlen(s); i++) {
       if(dic[s[i]-'a']-- == 1)	
          result[cnt++] = s[i]; 
    }
    result[cnt] = '\0';

    return result;
}

/*
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> cnts;
        string ret;
        stack<char> stk;
        vector<bool> isVisited(26, false);
        for (char each : s) cnts[each] ++;
        for (int i = 0; i < s.size(); cnts[s[i]] --, ++ i) {
            if (isVisited[s[i] - 'a'] || (!stk.empty() && stk.top() == s[i])) continue;
            while (!stk.empty() && stk.top() > s[i] && cnts[stk.top()] > 0) {
                isVisited[stk.top() - 'a'] = false;
                stk.pop();
            }
            stk.push(s[i]);
            isVisited[s[i] - 'a'] = true;
        }
        while (!stk.empty()) {
            ret.push_back(stk.top());
            stk.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
*/

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

   return 0;
}
