package com.leetcode;

import java.lang.reflect.Array;
import java.util.*;

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

    public int[] intersection_hash(int[] nums1, int[] nums2) {
        if (nums1 == null || nums2 == null) {
            return null;
        }
        BitSet s = new BitSet();
        BitSet interSet = new BitSet();

        for (int i : nums1) {
            s.set(i);
        }

        int m = 0;
        for (int k : nums2) {
            if (s.get(k) == true && interSet.get(k) == false) {
                interSet.set(k);
                m++;
            }
        }
        int[] nums3 = new int[m];
        int n = 0;
        for (int i = 1; i <= interSet.size(); i++) {
            if (interSet.get(i))
                nums3[n++] = i;
        }

        return nums3;
    }

    /**
     * 350. Intersection of Two Arrays II
     * Refer to: https://leetcode.com/problems/intersection-of-two-arrays-ii/
     *
     * @param nums1   array of numbers
     * @param nums2   array of numbers
     * @return intersection of two arrays
     */
    public int[] intersect(int[] nums1, int[] nums2) {
        Map<Integer, Integer> m1 = new HashMap<>();
        Map<Integer, Integer> m2 = new HashMap<>();

        for (int k: nums1)
            if (!m1.containsKey(k))
                m1.put(k, 1);
            else
                m1.put(k, m1.get(k) + 1);

        int m = 0;
        for (int k: nums2) {
            if (m1.containsKey(k) && m1.get(k) > 0) {
                m++;
                m1.put(k, m1.get(k)-1);

                if (!m2.containsKey(k)) {
                    m2.put(k, 1);
                } else {
                    m2.put(k, m2.get(k) + 1);
                }
            }
        }

        int[] res = new int[m];
        int cnt = 0;

        for (int k: m2.keySet())
            for (int i = 0, n = m2.get(k); i < n; i++) {
                res[cnt++] = k;
            }

        return res;
    }

}
