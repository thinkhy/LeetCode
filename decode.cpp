#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        
    long long s1, s2, s3;
    char c2,c3;
    int  i = 0;
    int num;

    s1 = 1;

    c2 = s[i++];
    if (c2 > '9' || c2 <= '0' ) {
        return 0;
    }
    else
        s2 = 1;


    c3 = s[i++];
    while(c3 <= '9' && c3 >= '0') {

        /*
        printf("s1:%d\n", s1);
        printf("s2:%d\n", s2);
        printf("s3:%d\n", s3);

        printf("c1:%c\n", c1);
        printf("c2:%c\n", c2);
        printf("c3:%c\n", c3);
        */


        if (c3 == '0') {
            if (c2 != '1' && c2 != '2')
               return 0;
            else
               s3 = s1;
        }
        else if (c2 == '0'){
               s3 = s2;
        }
        else {
            if ((c2-'0')*10 + (c3-'0')  <= 26) 
                s3 = s1 + s2;
            else
                s3 = s2;
        }

        s1=s2;
        s2=s3;
        s3=0;
        c2=c3;
        c3 = s[i++];
    }


    return s2;

        
    }
};

int main() {
    Solution s;
    printf("0: %d\n", s.numDecodings("0"));
    printf("3: %d\n", s.numDecodings("3"));
    printf("100: %d\n", s.numDecodings("100"));
    printf("10: %d\n", s.numDecodings("10"));
    printf("144: %d\n", s.numDecodings("144"));
    printf("101: %d\n", s.numDecodings("101"));
    printf("1029: %d\n", s.numDecodings("1029"));
    printf("3: %d\n", s.numDecodings("3"));
    printf("3: %d\n", s.numDecodings("3"));
printf("1029: %d\n", s.numDecodings("1029"));
    printf("3: %d\n", s.numDecodings("3"));
    printf("3: %d\n", s.numDecodings("3"));
    printf("30: %d\n", s.numDecodings("30"));
    printf("107: %d\n", s.numDecodings("107"));
    printf("207: %d\n", s.numDecodings("207"));
    printf("4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948: %d\n", s.numDecodings("4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948"));

    return 0;
}
