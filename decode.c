#include <stdio.h>
#include <assert.h>

class Solution {
public:
    int numDecodings(string s) {
        
    int s1, s2, s3;
    char c1,c2,c3;
    int  i = 0;
    int num;


    s1 = 1;

    c1 = s[i++];
    if (c1 > '9' || c1 <= '0' ) {
        //printf("0\n");
        return 0;
    }

    assert(c1 != '0');

    c2 = s[i++];
    if (c1 > '9' || c1 < '0' ) {
        //printf("1\n");
        return 1;
    }

    num = (c1-'0')*10 + (c2-'0');
    if (num > 0 && num <= 26) {
        if (c2 != 0)
            s2 = 2;
        else
            s2 = 1;
    }
    else {
        s2 = 1;
    }

    c3 = s[i++];
    while(c3 <= '9' && c3 >= '0') {

        if (c3 == '0') {
            if (c2 != '1' || c2 != '2')
               return 0;
            else
               s3 = s1;
        }
        else if (c2 == '0'){
            if (c1 != '1' || c1 != '2')
               return 0;
            else
               s3 = s2;
        }
        else {
            if ((c2-'0')*10 + (c3-'0')  <= 26) 
                s3 = 2 * s1;
            else 
                s3 = s1;

            if ((c1-'0')*10 + (c2-'0') <= 26) 
                s3++;
        }

        s1=s2;
        s2=s3;
        c1=c2;
        c2=c3;
        c3 = s[i++];
    }

    return s2;

        
    }
};

int main() {
    Solution s;
    printf("0: %d\n", s.numDecodings("0"));
    printf("100: %d\n", s.numDecodings("100"));
    printf("12: %d\n", s.numDecodings("12"));
    printf("144: %d\n", s.numDecodings("144"));

    return 
}
