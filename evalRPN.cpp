#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstdio>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << (a) << endl;

/*******************************************************************************************************************
 *
 * Evaluate Reverse Polish Notation
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * 
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 * 
 * Some examples:
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 *
 ************************************************************************************************************************/


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> num;

        for(int i = 0; i < tokens.size(); i++) {
            string cur = tokens[i];

            // hit a number, push it into stack
            if((cur[0] == '-' && cur.size() > 1) ||  (cur[0] >= '0' && cur[0] <= '9') ) {
                num.push(atoi(cur.c_str()));
            }
            else { // hit an operand, calculate the result
                int res;
                int right = num.top();
                num.pop();
                int left = num.top();
                num.pop();

                // valid operators are +, -, *, /.
                switch(cur[0]) {
                    case '+':
                        res = left + right;
                        break;
                    case '-':
                        res = left - right;
                        break;
                    case '*':
                        res = left * right;
                        break;
                    case '/':
                        res = left / right;
                        break;
                }
                // and push the result into stack
                num.push(res);
            }
        }

        return num.empty() ? 0 : num.top();
    }
};

int main() {
    Solution slt;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    DE(slt.evalRPN(tokens));
    vector<string> tokens1 = {"4", "13", "5", "/", "+"};
    DE(slt.evalRPN(tokens1));

    vector<string> tokens2 = {"-1", "1", "*", "-1", "+"};
    DE(slt.evalRPN(tokens2));
    
    return 0;
}


