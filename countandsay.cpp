#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
#include <iterator>
#include <cstdio>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
       string str; 
       if(n <= 0) return str;

       str="1";
       for(int i = 2; i <= n; i++) {
           stringstream sout;
           int pos = 0;
           int len = str.size();
           while(pos<len) {
               char cur=str[pos];
               int k=0;
               for(;pos<len && str[pos]== cur; pos++,k++);
               sout << k << cur;
           }
           str = sout.str();
       }

       return str;
    }
};


int main() {
    Solution s;
    for(int i = 0; i < 10; i++)
        cout << s.countAndSay(i) << endl;
     

    return 0;
}





