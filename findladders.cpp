#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

/**********************************************************************************
 * To compile: g++ findladders.cpp -std=c++0x
 *
 * Given two words (start and end), and a dictionary, find all shortest transformation 
 * sequence(s) from start to end, such that:
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the dictionary
 * For example,
 *   Given
 *   start = "hit"
 *   end = "cog"
 *   dict = ["hot","dot","dog","lot","log"]
 *   Return
 *     [
 *       ["hit","hot","dot","dog","cog"],
 *       ["hit","hot","lot","log","cog"]
 *     ]
 *   Note:
 *   All words have the same length.
 *   All words contain only lowercase alphabetic characters.
 *
 * My solution: 
 *   s0: insert start to queue
 *   s1: pull a string from queue, find next word in the set with distance=1
 *   s2: if next word is next to end word, output the sequence of strings
 *   s2: extract next word it from dict 
 *   s3: if next work is not next to end, push next word into tail of queue
 *   s4: Loop to s1   
 *
 **********************************************************************************/

class Solution {

    inline bool isAdjacent(const string& lhs, const string& rhs) {
        int changes = 0;
        for(int i = 0; changes < 2&&i < 3; i++) {   
            if (lhs[i] != rhs[i]) changes++;
        }

        return changes == 1;
    }

public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {

        vector<vector<string> > results;
        map<string, vector<string> > tree;                        
        map<string, string> trace;
        queue<string> sq;

        if (isAdjacent(start, end)) {
            cout << start << end << endl;
            vector<string> tmp;
            tmp.push_back(start);
            tmp.push_back(end);
            results.push_back(tmp);

            return results;
        }

        vector<string> tmp;
        tree.insert(make_pair(start, tmp));

        for(unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++) 
        {
            if (1 == isAdjacent(*it, start)) {
                tree[start].push_back(*it);
            }

            unordered_set<string>::iterator nextit = it;
            nextit++;
            for(; nextit != dict.end(); nextit++) {
                if (1 == isAdjacent(*it, *nextit)) {
                    if (tree.find(*it) != tree.end() ) {
                        tree[*it].push_back(*nextit);
                    }
                    else {
                        vector<string> tmp;
                        tmp.push_back(*nextit);
                        tree.insert(make_pair(*it, tmp));
                    }

                    if (tree.find(*nextit) != tree.end() ) {
                        tree[*nextit].push_back(*it);
                    }
                    else {
                        vector<string> tmp;
                        tmp.push_back(*it);
                        tree.insert(make_pair(*nextit, tmp));
                    }
                }
            }
        }

        sq.push(start);
        while(!sq.empty()) {
            string cur = sq.front();
            sq.pop();
            // cout << "cur: " << cur << endl;
            if (isAdjacent(cur, end)) {
               vector<string> result;
               stack<string> tmpstack;
               string parent = cur;

               tmpstack.push(end);

               do {
                   tmpstack.push(parent);
                   parent = trace[parent];
               } while(parent != start);

               tmpstack.push(start);

               while(!tmpstack.empty()) {
                   result.push_back(tmpstack.top()); 
                   tmpstack.pop();
               }
               results.push_back(result);
            }
            else {
                for(int i = 0; i < tree[cur].size(); i++) {
                    string next = tree[cur][i];
                    if (trace.find(next) != trace.end()) 
                        continue;
                    trace.insert(make_pair(next, cur));
                    sq.push(next);
                }
            }
        }
        

        return results;
    }
};


int main() {
    Solution s;
    string start = "hit";    
    string end   = "cog";    
    unordered_set<string> dict; 
    /*dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");*/

    start = "set"; end =  "oar";
    dict.insert("oar");
    dict.insert("sat");
    dict.insert("dip");
    dict.insert("sir");
    dict.insert("lap");
    dict.insert("tat");
    dict.insert("off");
    dict.insert("din");
    dict.insert("caw");
    dict.insert("hob");
    dict.insert("lie");
    dict.insert("tam");dict.insert("wyo");dict.insert("noe");dict.insert("rob");dict.insert("nay");dict.insert("hah");dict.insert("box");dict.insert("mac");dict.insert("low");dict.insert("tin");dict.insert("tip");dict.insert("set");dict.insert("geo");dict.insert("too");dict.insert("tea");dict.insert("fin");dict.insert("tad");dict.insert("zed");dict.insert("key");dict.insert("ray");dict.insert("shy");dict.insert("min");dict.insert("kin");dict.insert("rep");dict.insert("now");dict.insert("ink");dict.insert("fag");dict.insert("fed");dict.insert("pas");dict.insert("huh");dict.insert("bad");dict.insert("oks");dict.insert("pan");dict.insert("kip");dict.insert("inc");dict.insert("bat");dict.insert("pop");dict.insert("pat");dict.insert("aol");dict.insert("cud");dict.insert("tan");dict.insert("car");dict.insert("hut");dict.insert("oat");dict.insert("gap");dict.insert("hes");dict.insert("hen");dict.insert("chi");

    vector<vector<string> > results = s.findLadders(start, end, dict);
    for(int i = 0; i < results.size(); i++ ) {
        for(int j = 0; j < results[i].size(); j++ ) {
            cout << results[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "[Done]" << endl;


}


