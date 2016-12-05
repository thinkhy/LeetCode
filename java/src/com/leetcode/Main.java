package com.leetcode;

public class Main {

    public static void main(String[] args) {
	   System.out.println("Hello, leetcode");
	   Solution s = new Solution();

	   /*
	   System.out.println(s.isPerfectSquare(10));
	   System.out.println(s.isPerfectSquare(16));
	   System.out.println(s.isPerfectSquare(14));
	   System.out.println(s.isPerfectSquare(2147483647));
	   */

	   int[] nums1 = {1, 2, 2, 1};
	   int[] nums2 = {2, 2};

	   int[] res = s.intersect(nums1, nums2);
	   System.out.println(java.util.Arrays.toString(res));

		nums1 = new int[]{};
		nums2 = new int[]{1};


		res = s.intersect(nums1, nums2);
		System.out.println(java.util.Arrays.toString(res));
    }
}
