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
private:
    void tracePath(map<string, vector<string> > &trace , 
                   const string &end, 
                   const string &start, 
                   vector<string> path,       
                   int depth,
                   vector<vector<string> > &results) {
        if (depth-- <= 0)  
            return;

        if (end == start) {
            path.push_back(start);
            reverse(path.begin(), path.end());
            results.push_back(path);
        }
        else {
            path.push_back(end);
            for(int i = 0; i < trace[end].size(); i++) {
                tracePath(trace, trace[end][i], start, path, depth, results);
            }
        }
    }

public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {

        vector<vector<string> > results;
        map<string, vector<string> > trace;
        queue<string> sq;
        unordered_set<string> unvisited(dict);
        unordered_set<string> visited;

        unordered_set<string>::iterator it = unvisited.end();
        for(it = unvisited.begin(); it != unvisited.end(); it++) {
            trace.insert(make_pair(*it, vector<string>()));  
        }

        trace.insert(make_pair(end, vector<string>()));  
        
        // BFS to find path to reach out end
        sq.push(start);
        unvisited.insert(end);

        int curlevel = 1;
        int nextlevel = 0;
        int depth = 0;
        bool found = false;
        string curword, nextword;

        while (!sq.empty()) {
            curword = sq.front();
            sq.pop();


            for(int i = 0; i < start.size(); i++) { 
                nextword = curword;
                for(char ch='a'; ch<='z'; ch++) {
                    if (curword[i] == ch) 
                        continue;
                    
                    nextword[i] = ch;
                    if(unvisited.find(nextword) != unvisited.end()) {
                        trace[nextword].push_back(curword);
                        if (visited.find(nextword) == visited.end()) {
                            visited.insert(nextword);
                            nextlevel++;
                            sq.push(nextword);

                            if(nextword == end && !found) {
                                depth++;
                                found = true;
                            }
                        }
                    }
                }
            }

            --curlevel;
            if (curlevel == 0) { // turn to next level child nodes(words)
                depth++;

                curlevel = nextlevel;
                nextlevel = 0;

                for (it = visited.begin(); it != visited.end(); it++) 
                    unvisited.erase(*it);

                visited.clear();

                if (found) {
                    vector<string> path;

                    // DFS to find path from end to start
                    tracePath(trace, end, start, path, depth, results);
                    break;
                }
            }
        } // while(!sq.empty())

        return results;
    }
};


int main() {
    Solution s;
    string start = "hit";    
    string end   = "cog";    
    unordered_set<string> dict; 
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");

    vector<vector<string> > results = s.findLadders(start, end, dict);
    for(int i = 0; i < results.size(); i++ ) {
        for(int j = 0; j < results[i].size(); j++ ) {
            cout << results[i][j] << "  ";
        }

        cout << endl;
    }

    dict.clear();
    start = "hot"; end="hoi";
    results = s.findLadders(start, end, dict);
    for(int i = 0; i < results.size(); i++ ) {
        for(int j = 0; j < results[i].size(); j++ ) {
            cout << results[i][j] << "  ";
        }

        cout << endl;
    }

    dict.clear();
    start = "lost"; end =  "miss";
    dict.insert("most");
    dict.insert("mist");
    dict.insert("miss");
    dict.insert("lost");
    dict.insert("fist");
    dict.insert("fish");
    results = s.findLadders(start, end, dict);
    for(int i = 0; i < results.size(); i++ ) {
        for(int j = 0; j < results[i].size(); j++ ) {
            cout << results[i][j] << "  ";
        }

        cout << endl;
    }



    dict.clear();
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

    results = s.findLadders(start, end, dict);
    for(int i = 0; i < results.size(); i++ ) {
        for(int j = 0; j < results[i].size(); j++ ) {
            cout << results[i][j] << "  ";
        }

        cout << endl;
    }

    cout << "[Done]" << endl;

}


