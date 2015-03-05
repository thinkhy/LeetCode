#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*************************************************************
 *
 * Given an input string, reverse the string word by word.
 * For example,
 *   Given s = "the sky is blue",
 *   return "blue is sky the".
 *
 * Clarification:
 *  * What constitutes a word?
 *    A sequence of non-space characters constitutes a word.
 *  * Could the input string contain leading or trailing spaces?
 *    Yes. However, your reversed string should not contain leading or trailing spaces.
 *  * How about multiple spaces between two words?
 *    Reduce them to a single space in the reversed string.
 *
 ******************************************************/

/**************************************************
 *
 * 1.split works in the string
 * 2.exchange position of (n)th word and (len-n+1)th word 
 * 3.Loop step2 until n>= len-n+1
 *
 **************************************************/
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.size(); i++) {
            if(s[i] !=
        }
    }
};

int main() {
    string str;
    Solution obj;

    str = "";
    obj.reverseWords(str);
    cout << str << endl;

    str = "abc";
    obj.reverseWords(str);
    cout << str << endl;

    str = "  the sky is blue         ";
    obj.reverseWords(str);
    cout << str << endl;

    return 0;
}
