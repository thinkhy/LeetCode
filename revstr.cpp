#include <iostream>
#include <string>
#include <vector>
using namespace std;


/**************************************************
 *
 * 1.split works in the string
 * 2.exchange position of (n)th word and (len-n+1)th word 
 * 3.Loop step2 until n>= len-n+1
 *
 **************************************************/
class Solution {
    string findWord(const string &s, int& pos) {
        string word;
        while(pos < s.size() && s[pos] == ' ') 
            pos++;

        while(pos < s.size() && s[pos] != ' ')   {
            word += s.substr(pos, 1);
            pos++;
        }

        return word;
    }
public:
    void reverseWords(string &s) {
       vector<string> words;
       int pos = 0; 
       while(pos < s.size()) { 
           string nextWord = findWord(s, pos);
           if (!nextWord.empty()) {
               words.push_back(nextWord);
           }
           else {
               break;
           }
       }
       s = "";
       for (int i = words.size() - 1; i>=0; i--) {
           if (i == (words.size() - 1))
             s += words[i];
           else {
             s += " ";
             s += words[i];
           }
               
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
