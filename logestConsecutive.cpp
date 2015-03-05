#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstring>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
       int len = num.size();
       unordered_map<int, pair<int, int>> seq; 
       int low, upper;
       int maxSeq = 0;

       for(int i = 0; i < len; i++) {
           if(seq.count(num[i]) == 0) { 
               seq[num[i]] = make_pair(num[i], num[i]);
               if(seq.count(num[i]-1) != 0) {
                  seq[num[i]].first = seq[num[i]-1].first;
               }
               if(seq.count(num[i]+1) != 0) {
                  seq[num[i]].second = seq[num[i]+1].second;
               }
               seq[seq[num[i]].first].second = seq[num[i]].second;
               seq[seq[num[i]].second].first = seq[num[i]].first;

               maxSeq = max(maxSeq, seq[num[i]].second-seq[num[i]].first+1);
           }
       }

       return maxSeq;
    }
};

int main() {
    Solution s;
    vector<int> num;
    cout << s.longestConsecutive(num) << endl;
    num.push_back(100);
    cout << s.longestConsecutive(num) << endl;
    num.push_back(4);
    cout << s.longestConsecutive(num) << endl;
    num.push_back(200);
    cout << s.longestConsecutive(num) << endl;
    num.push_back(1);
    cout << s.longestConsecutive(num) << endl;
    num.push_back(3);
    cout << s.longestConsecutive(num) << endl;
    num.push_back(2);

    cout << s.longestConsecutive(num) << endl;

    return 0;
}

