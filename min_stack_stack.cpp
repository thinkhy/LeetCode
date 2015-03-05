#include <iostream>
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
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;


/*
  Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

   push(x) -- Push element x onto stack.
   pop() -- Removes the element on top of the stack.
   top() -- Get the top element.
   getMin() -- Retrieve the minimum element in the stack.

*/


class MinStack {
    stack<int> num_stack;
    stack<int> min_stack;

public:
    MinStack() {
    }

    void push(int x) {
        num_stack.push(x);
        if(min_stack.empty() || min_stack.top() >= x)
            min_stack.push(x);
    }

    void pop() {
        if(min_stack.top() == num_stack.top())
            min_stack.pop();
        num_stack.pop();
    }

    int top() {
       return num_stack.top();
    }

    int getMin() {
       return min_stack.top();
    }
};


int main() {
    MinStack s; 

    s.push(512);
    s.push(-1024);
    s.push(-1024);
    s.push(512);
    s.pop();

    DE(s.getMin());
    s.pop();
    DE(s.getMin());
    s.pop();
    DE(s.getMin());

    return 0;
}



