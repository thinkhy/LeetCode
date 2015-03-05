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
#include <bitset>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstdio>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << (a) << endl;

/*******************************************************************************************************************
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 * 
 * For example,
 *  path = "/home/", => "/home"
 *  path = "/a/./b/../../c/", => "/c"
 *  click to show corner cases.
 * 
 * Corner Cases:
 *  Did you consider the case where path = "/../"?
 *  In this case, you should return "/".
 *  Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 *  In this case, you should ignore redundant slashes and return "/home/foo".
 *
 ************************************************************************************************************************/


class Solution {
public:
    string simplifyPath(string path) {
        string res;
        if(path.empty()) 
            return res;

        stack<string> st;
        // assume the first character must be '/'
        st.push("/");
        
        int pos = 1;
        int len = path.size();
        while(pos < len) {
            string cur;

            // skip multiple slash
            while(pos < len && path[pos] == '/') pos++;

            // extract directory until hitting '/'
            while(pos < len && path[pos] != '/') { 
                cur += path[pos]; 
                pos++;
            }

            if(cur == ".") {   // keep current directory, no need to push
                continue;
            }
            else if(cur == ".." ) { // jump to parent directory until root derectory
                if(st.top() != "/")
                    st.pop();  
            }
            else if(!cur.empty()) { // normal directory
                st.push(cur);
            }
        }
        
        // combine the whole path from right to left
        while(!st.empty()) {
            if(res.empty())
                res = st.top();
            else  {
                if(st.size() == 1) // only root directory left
                    res = st.top() + res;
                else               // normal child directory appends a '/'
                    res = st.top() + "/" + res;
            }
            st.pop();
        }

        return res;
    }
};

int main() {
    Solution slt;
    DE(slt.simplifyPath("/"));
    DE(slt.simplifyPath("/home/"));
    DE(slt.simplifyPath("/a/./b/../../c/"));
    DE(slt.simplifyPath("/../"));
    DE(slt.simplifyPath("/home//foo/"));

    return 0;
}

