/*********************************************************************************
 *
 * Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
 *
 * Given an integer matrix, find the length of the longest increasing path.
 *
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 *
 * Example 1:
 *
 * nums = [
 *   [9,9,4],
 *     [6,6,8],
 *       [2,1,1]
 *       ]
 *       Return 4
 *       The longest increasing path is [1, 2, 6, 9].
 *
 *       Example 2:
 *
 *       nums = [
 *         [3,4,5],
 *           [3,2,6],
 *             [2,2,1]
 *             ]
 *             Return 4
 *             The longest increasing path is [3, 4, 5, 6]. Moving diagonally is
 *             not allowed.
 *
 ************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define DE(x)      do { printf("%s:%d\n", #x, (x)); } while(0);
#define swap(a, b) do { (a)=(a)^(b);(b)=(a)^(b);(a)=(b)^(a); } while(0)
#define min(a, b)  ((a) > (b) ? (b) : (a))

int longestIncreasingPath(int** matrix, int matrixRowSize, int matrixColSize) {

}

int main() {

}


