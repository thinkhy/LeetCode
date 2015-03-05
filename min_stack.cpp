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
    deque<int> stack;
    int min;
public:
    MinStack() {
    }

    void push(int x) {
       if(stack.empty())
           min = 0;
       else if(x < stack[min]) 
           min = stack.size();
       stack.push_back(x); 
    }

    void pop() {
       stack.pop_back(); 
       if(stack.size() == min) {
           min = 0;
           for(int i = 1; i < stack.size(); i++)
               if(stack[i]<stack[min])
                   min = i;
       }
    }

    int top() {
       return stack.back(); 
    }

    int getMin() {
       if(!stack.empty())
           return stack[min]; 
       else
           return INT_MAX; 
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



