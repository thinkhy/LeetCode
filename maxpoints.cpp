#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <limits>
#include <iterator>
#include <utility>
#include <cmath>
using namespace std;


struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
};

class Solution {
#define DOUBLE_PRECISION  0.00001
    class Line {
    public:
        Line() { slope=k=0; };
        Line(double _slope, double _k): slope(_slope),k(_k) {}

        bool operator<(const Line& rhs) const {
            return rhs.slope - slope > DOUBLE_PRECISION
                    || rhs.k - k > DOUBLE_PRECISION;
        }

        double slope, k;
    };


public:

    int maxPoints(vector<Point> &points) {

        // the points (a,b), (m,n) and (x,y) are collinear if and only if
        // (n-b)(x-m)=(y-n)(m-a)
        int num = points.size();
        if(num == 0) return 0;
        if(num == 1 || num == 2) return num;

        // sort points by the vaule of x
        // if not sort, will fail for the case:
        //  Input:   [(84,250),(0,0),(1,0),(0,-70),(0,-70),(1,-1),(21,10),(42,90),(-42,-230)]
        //  Output:  5
        //  Expected:    6
        for(int i = 0; i < num-1; i++) {
            bool flag = false;
            for(int j = 0; j+1 < num-i; j++) {
                if (points[j].x > points[j+1].x) {
                    Point tmp = points[j+1];
                    points[j+1] = points[j];
                    points[j] = tmp;
                    flag = true;
                }
            }

            if (flag == false)
                break;
       }
        
        int maxpoints = 0;

        for(int i = 0; i < num - maxpoints; i++) { 
            Line key;
            map<Line, int> lines;
            int coincident = 0;

            for(int j = i+1; j < num; j++) {
                double slope, k;

                // current point coincides with connected point
                if (j>0 && (points[j].x == points[i].x && points[j].y == points[i].y)) {
                    coincident++;
                    continue;
                }

                if (points[j].x == points[i].x) {
                   key = Line(numeric_limits<double>::max(), points[i].x); 
                }
                else if (points[j].y == points[i].y) {
                   key = Line(0, points[i].y); 
                }
                else {
                    slope = ((double)(points[i].y - points[j].y))/(points[i].x - points[j].x);
                    k = points[i].y - points[i].x * slope;
                    key = Line(slope, k);
                }

                if (lines.find(key) != lines.end()) {
                    lines[key]++;
                }
                else {
                    lines.insert(make_pair(key, 1));
                }

            } // for j

            int curMax = 0;
            for(map<Line, int>::iterator it = lines.begin(); it != lines.end(); it++) {
                if (it->second > curMax) {
                    curMax = it->second;
                }
            }

            curMax = 1 + coincident + curMax;
            maxpoints = max(maxpoints, curMax); 
        } // for i


        return maxpoints;
    }
};

int main() {
    Solution s;
    vector<Point> points;

    points.push_back(Point(0,0));
    points.push_back(Point(1,1));
    points.push_back(Point(2,2));
    points.push_back(Point(3,4));
    points.push_back(Point(5,5));
    points.push_back(Point(6,5));
    cout << s.maxPoints(points) << endl;

    points = vector<Point>();
    points.push_back(Point(1,1));
    points.push_back(Point(1,1));
    points.push_back(Point(1,1));
    cout << s.maxPoints(points) << endl;

    points = vector<Point>();
    points.push_back(Point(1,1));
    points.push_back(Point(1,1));
    points.push_back(Point(2,3));
    cout << s.maxPoints(points) << endl;

    points = vector<Point>();
    points.push_back(Point(1,1));
    points.push_back(Point(1,1));
    points.push_back(Point(2,2));
    points.push_back(Point(2,2));
    cout << s.maxPoints(points) << endl;

    return 0;
}

