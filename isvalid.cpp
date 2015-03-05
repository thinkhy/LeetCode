#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
    bool isMatched(const char left, const char right) {
        switch (left) {
            case '(': return right==')';
            case '{': return right=='}';
            case '[': return right==']';
            default:  return false;
        }
    }

public:
    bool isValid(string s) {
       bool ret = true;
       stack<char> st; 

       for(int i = 0; i < s.size(); i++) {
           if (s[i] == '(' || s[i] == '{' || s[i] == '[')
               st.push(s[i]);
           else if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
               if (!st.empty() && isMatched(st.top(), s[i])) {
                   st.pop();
               }
               else {
                   return false;
               }
           }
       }

       return st.empty();
    }
};

int main() {
    Solution s;
    string str="()";
    cout << str << ": " << s.isValid(str) << endl;

    str="()[]{}";
    cout << str << ": "<< s.isValid(str) << endl;

    str="{([{}])}";
    cout << str << ": "<< s.isValid(str) << endl;

    str="(]";
    cout << str << ": "<< s.isValid(str) << endl;

    str="([)]";
    cout << str << ": "<< s.isValid(str) << endl;

    str="([{]}])}";
    cout << str << ": "<< s.isValid(str) << endl;

    str="";
    cout << str << ": " << s.isValid(str) << endl;

    str="(";
    cout << str << ": " << s.isValid(str) << endl;

    str=")";
    cout << str << ": " << s.isValid(str) << endl;

    return 0;
}
