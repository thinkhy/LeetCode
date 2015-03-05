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
 Given a collection of intervals, merge all overlapping intervals.

 For example,
    Given [1,3],[2,6],[8,10],[15,18],
    return [1,6],[8,10],[15,18].
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
};

int main() {
    Solution s; 

    vector<Interval> ints;
    ints.push_back(Interval(2, 9));

    vector<Interval> re = s.merge(ints);
    for(int i = 0; i < re.size(); i++) {
        cout << re[i] << endl;
    }
    cout << "=======================================" << endl;
    ints.clear();

    ints.push_back(Interval(8, 10));
    ints.push_back(Interval(2, 6));
    ints.push_back(Interval(1, 3));
    ints.push_back(Interval(15,18));

    re = s.merge(ints);
    for(int i = 0; i < re.size(); i++) {
        cout << re[i] << endl;
    }
    cout << "=======================================" << endl;
    ints.clear();

    ints.push_back(Interval(2, 3));
    ints.push_back(Interval(2, 2));
    ints.push_back(Interval(3, 3));
    ints.push_back(Interval(1,3));
    ints.push_back(Interval(5,7));
    ints.push_back(Interval(2,2));
    ints.push_back(Interval(4,6));

    re = s.merge(ints);
    for(int i = 0; i < re.size(); i++) {
        cout << re[i] << endl;
    }

    return 0;
}



