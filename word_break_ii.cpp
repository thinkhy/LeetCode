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
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/
class Solution {
public:
    void find_path(string& s, 
                   unordered_map<int, vector<int> >& trace,
                   vector<string> &re,
                   string path,
                   int cur_pos) {
        if(cur_pos == -1) {
            re.push_back(path);
            return;
        }
        for(int i = 0; i < trace[cur_pos].size(); i++) {
            int pre_pos = trace[cur_pos][i];

            string tmp = path;
            if(cur_pos != s.size()-1)
                tmp.insert(0, 1, ' ');
            tmp.insert(0, s.substr(pre_pos+1, cur_pos-pre_pos));
            find_path(s, trace, re, tmp, pre_pos);
        }

        return;
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> re;
        
        unordered_map<int, vector<int> > trace;
        unordered_set<string>::iterator it = dict.end();
        
        trace[-1] = vector<int>();
        for(int i = 0; i < s.size(); i++) {
            for(it = dict.begin(); it != dict.end(); it++) {
                int len = it->size();
                if(i+1 >= len && *it == s.substr(i - len + 1, len)
                        && trace.find(i-len) != trace.end()) {
                    trace[i].push_back(i-len);
                }
            }
        }

        /*for(unordered_map<int, vector<int> >::iterator it=trace.begin();
            it != trace.end(); it++) {
            vector<int> pre = it->second;
            cout << it->first << ": ";
            for(int i = 0; i < pre.size(); i++) {
                cout << pre[i] << " ";
            }
            cout << endl;
        }
        */
        
        int len = s.size();
        string path;
        find_path(s, trace, re, path, len-1);

        return re;
    }
};

int main() {
    Solution slt;
    string s = "catsanddog";
    unordered_set<string> dict;
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");

    vector<string> re = slt.wordBreak(s, dict);
    for(int i = 0; i < re.size(); i++)
        cout << re[i] << endl;

    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    dict.clear();
    dict.insert("a");
    dict.insert("aa");
    dict.insert("aaa");
    dict.insert("aaaa");
    dict.insert("aaaaa");
    dict.insert("aaaaaa");
    dict.insert("aaaaaaa");
    dict.insert("aaaaaaaa");
    dict.insert("aaaaaaaaa");
    dict.insert("aaaaaaaaaa");

    re = slt.wordBreak(s, dict);
    for(int i = 0; i < re.size(); i++)
        cout << re[i] << endl;

    return 0;
}



