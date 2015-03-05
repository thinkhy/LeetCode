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
#include <memory>
#include <limits>
#include <utility>
#include <cstdio>
#include <cstring>
#include <climits>      // for INT_MAX
using namespace std;

#define DE(a) cout << #a << ": " << (a) << endl;
#define EXPECT(a, b) cout << #a << ": result: " << (a) \ 
                                << "  expect: " << (b) << endl;

/*********************************************************************************************
 *
 * LRU Cache 
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and set.
 * 
 *  get(key) - Get the value (will always be positive) of the key if the key exists 
 *             in the cache, otherwise return -1.
 *  set(key, value) - Set or insert the value if the key is not already present. 
 *                    When the cache reached its capacity, it should invalidate the least recently 
 *                    used item before inserting a new item.
 * 
 * LRU cache: http://en.wikipedia.org/wiki/Cache_algorithms#LRU
 *
 *********************************************************************************************/

class LRUCache{
    struct LRUNode {
        int key;
        int value;
        LRUNode(int key, int value) {
            this->key = key;
            this->value = value;
        }
    };

    int capacity;
    list<LRUNode> nodes;
    unordered_map<int, list<LRUNode>::iterator > cache;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;        
    }
    
    int get(int key) {
        // cache hit
        if(cache.find(key) != cache.end()) {   
            // insert the current item into the head of list
            nodes.splice(nodes.begin(), nodes, cache[key]);
            cache[key] = nodes.begin();
            return cache[key]->value;
        }
        // cache missed
        else
            return -1;
    }
     
    /* 
     * set(key, value) - Set or insert the value if the key is not already present. 
     *                   When the cache reached its capacity, it should invalidate 
     *                   the least recently used item before inserting a new item.
     *
     */
    void set(int key, int value) {
        // key existed, just update value
        if(cache.find(key) != cache.end()) {
            cache[key]->value = value;
            // move current node to the front
            nodes.splice(nodes.begin(), nodes, cache[key]);
        }
        // otherwise, insert new key   
        else {
           // cache is full, remove the tail of list 
           if (cache.size() == capacity) { 
               cache.erase(cache.find(nodes.back().key));
               nodes.pop_back();
           }

           // insert current node to the head of list
           nodes.push_front(LRUNode(key, value));
           cache[key] = nodes.begin();
        }

        return;
    }
};

int main() {
    LRUCache s(2);
    s.set(2,1);
    s.set(1,1);
    s.set(2,3);
    s.set(4,1);
    DE(s.get(1));
    DE(s.get(2));

    return 0;
} 
