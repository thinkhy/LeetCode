package main

import (
	"fmt"
)

/***************************************************************************

Given a sorted array and a target value,
return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
 [1,3,5,6], 5 → 2
 [1,3,5,6], 2 → 1
 [1,3,5,6], 7 → 4
 [1,3,5,6], 0 → 0

****************************************************************************/

func searchInsert(nums []int, target int) int {
	if len(nums) == 0 {
		return 0
	}

	l := 0
	h := len(nums) - 1
	for l < h {
		m := (l + h) / 2
		if nums[m] == target {
			return m
		}
		if nums[m] < target {
			l = m + 1
		} else {
			h = m - 1
		}
	}
	if nums[l] >= target {
		return l
	} else {
		return l + 1
	}
}

func main() {
	nums := []int{1, 3, 5, 6}
	fmt.Println(searchInsert(nums, 5))
	fmt.Println(searchInsert(nums, 2))
	fmt.Println(searchInsert(nums, 7))
	fmt.Println(searchInsert(nums, 0))
}
