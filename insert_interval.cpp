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

#define DE(a) cout << #a << ": " << a << endl;

/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

    Example 1:
        Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

    Example 2:
        Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/


/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
    friend ostream& operator<<(ostream& os, const Interval& rhs) {
        os << "start: " << rhs.start << "  end: " << rhs.end;
        return os;
    }
};


class Solution {
public:
    void quick_sort(vector<Interval>& ints, int l, int h) {
        if(l >= h) return;
        
        int i = l, j = h;
        Interval pivot = ints[l];

        while(i<j) {

            // locate to an element less than pivot from right-most
            while(i<j && (ints[j].start > pivot.start
                    ||(ints[j].start == pivot.start && ints[j].end >= pivot.end))) {
                j--;
            }
            if(i<j)
                ints[i] = ints[j];

            // locate to an element greater than pivot from left-most
            while(i<j && (ints[i].start < pivot.start
                    ||(ints[i].start == pivot.start && ints[i].end < pivot.end))) {
                i++;
            }
            if(i<j)
                ints[j] = ints[i];
        }
        ints[i] = pivot;
        
        // divide and conque
        quick_sort(ints, l,   i-1);
        quick_sort(ints, i+1, h);
        
        return;
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> re;
        if(intervals.empty()) return re;

        // sort 
        quick_sort(intervals, 0, intervals.size()-1);
        
        int s = intervals[0].start;
        int e = intervals[0].end;

        // merge
        for(int i = 1; i < intervals.size(); i++) {
            Interval cur = intervals[i];
            if(cur.start > e) {
                re.push_back(Interval(s, e));
                s = cur.start;
                e = cur.end;
            }
            else if(cur.end > e) {
                e = cur.end;
            }
        }
        re.push_back(Interval(s, e));

        return re;
    }

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        intervals.push_back(newInterval);    

        return merge(intervals);
    }
};

int main() {
    Solution s; 

    vector<Interval> ints;
    ints.push_back(Interval(2, 9));

    vector<Interval> re = s.merge(ints);
    for(int i = 0; i < re.size(); i++) {
        cout << re[i] << endl;
    }

    Interval new_one;

    cout << "=======================================" << endl;

    /*
    Example 1:
        Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
    */
    ints.clear();
    ints.push_back(Interval(1, 3));
    ints.push_back(Interval(6, 9));

    new_one = Interval(2,5);

    re = s.insert(ints, new_one);
    for(int i = 0; i < re.size(); i++) {
        cout << re[i] << endl;
    }

    cout << "=======================================" << endl;

    /*
    Example 2:
        Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
    */
    ints.clear();
    ints.push_back(Interval(1, 2));
    ints.push_back(Interval(3, 5));
    ints.push_back(Interval(6, 7));
    ints.push_back(Interval(8, 10));
    ints.push_back(Interval(12, 16));

    new_one = Interval(4,9);

    re = s.insert(ints, new_one);
    for(int i = 0; i < re.size(); i++) {
        cout << re[i] << endl;
    }

    return 0;
}



