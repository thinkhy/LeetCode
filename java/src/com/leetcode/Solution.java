package com.leetcode;

/**
 * Created by huangye on 11/28/16.
 */
public class Solution {
    public boolean isPerfectSquare(int num) {
        long l = 1;
        long h = num;
        while(l <= h) {
            long m = l + (h-l)/2;
            long s = m*m;
            if (s == num) {
                //System.out.printf("%d: \n", m);
                return true;
            } else if (s < num) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return false;
    }
}
