#include <iostream>
#include <string>
#include <sstream>
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
#include <iterator>
#include <cstdio>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*
 * Clone Graph
 *
 * Clone an undirected graph. 
 * Each node in the graph contains a label and a list of its neighbors.
 *
 */

/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};

};

class Solution {
public:
    UndirectedGraphNode* copy_node(unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& org2dup,                                   
                                   UndirectedGraphNode *n0) {
        if(n0 == NULL)
            return NULL;

        UndirectedGraphNode *dup = new UndirectedGraphNode(n0->label);
        org2dup[n0] = dup;
        dup->neighbors = n0->neighbors;
        for(int i = 0; i < (dup->neighbors).size(); i++) {
            UndirectedGraphNode *&cur = (dup->neighbors)[i] ;
            if(cur != n0 && org2dup.find(cur) == org2dup.end())
                copy_node(org2dup, cur);
        }

        return dup;
    }

    void update_node(unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& org2dup,
                     unordered_set<UndirectedGraphNode*>& visited,
                     UndirectedGraphNode *n0 
                                     ) {
        if(n0 == NULL)
            return;

        visited.insert(n0);
        for(int i = 0; i < (n0->neighbors).size(); i++) {
            UndirectedGraphNode *&cur = (n0->neighbors)[i];
            cur = org2dup[cur];
            if(visited.find(cur) == visited.end()) 
                update_node(org2dup, visited, cur);
        }
        return;
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
         UndirectedGraphNode *re;

         unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> org2dup;
         unordered_set<UndirectedGraphNode*> visited;

         re = copy_node(org2dup, node);
         update_node(org2dup, visited, re);

         return re;
    }
};

int main() {
    Solution s;

    UndirectedGraphNode n0(0);
    UndirectedGraphNode n1(1);
    UndirectedGraphNode n2(2);
    UndirectedGraphNode n3(3);

    n0.neighbors.push_back(&n1);
    n0.neighbors.push_back(&n2);
    n0.neighbors.push_back(&n3);
    n1.neighbors.push_back(&n0);
    n2.neighbors.push_back(&n0);
    n3.neighbors.push_back(&n0);
    UndirectedGraphNode *m0 = s.cloneGraph(&n0);

    cout << m0->label << " ";
    vector<UndirectedGraphNode *> tmp = m0->neighbors;
    for(int i = 0; i < tmp.size(); i++) {
        cout << tmp[i]->label << " ";
    }

    return 0;
}








