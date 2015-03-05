#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
       typedef  map< string, vector<string> > Msv;
       Msv strmap; 
       string tmp;
       for (int i = 0; i < strs.size(); i++) {
            tmp = strs[i];
            sort( tmp.begin(), tmp.end() );
            // tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());;

            if(strmap.find(tmp) == strmap.end())
                strmap[tmp] = vector<string>();

            strmap[tmp].push_back(strs[i]);
       }

       vector<string> results;
       for(map< string, vector<string> >::iterator it = strmap.begin(); it != strmap.end(); it++) {
           if ((it->second).size() > 1) {
               results.insert(results.begin(), 
                             (it->second).begin(),(it->second).end()); 
           }
       }

       return results;
    }
};

int main() {
    Solution s;
    vector<string> strs;
    strs.push_back("tea");
    strs.push_back("and");
    strs.push_back("ate");
    strs.push_back("eat");
    strs.push_back("dan");
    vector<string> result = s.anagrams(strs);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
