#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BFS(int root, int n, int *graph, int *queue) {
    int qsize = 0;
    char *visited = (char*)malloc(n);
    queue[qsize++] = root;
    while(qsize > 0) {
        for() {
        }
    }

    free(visited);
    return 0;
}

/**
 *  * Return an array of size *returnSize.
 *  * Note: The returned array must be malloced, assume caller calls free().
 *  */
int* findMinHeightTrees(int n, int** edges, int edgesRowSize, int edgesColSize, int* returnSize) {
    int row, col;
    returnSize = (int*)malloc(sizeof(int));
    int *results =  (int*)malloc(n*sizeof(int));
    *returnSize = 0;

    if (n == 0)
        return NULL;

    if (n == 1) {
        results[0] = 0;
        return results;
    }

    if (n == 2) {
        results[0] = 0;
        results[1] = 1;
        return results;
    }

    printf("row:%d, col:%d\n", edgesRowSize, edgesColSize);

    // Caculate degrees
    int *degree = (int*)malloc(n*sizeof(int));
    int *graph = (int*)malloc(n*sizeof(int));
    int *queue  =  (int*)malloc(n*sizeof(int));
    memset(degree, 0, n*sizeof(int));
    for(row = 0; row < edgesRowSize; row++) {
           degree[edges[row][0]]++;
           degree[edges[row][1]]++;
           graph[edges[row][0]] = edges[row][1];
           graph[edges[row][1]] = edges[row][0];
   }

    // BFS trees rooted from points with degree>1
    int i, cur_height, min_height;
    min_height = n;
    for(i = 0; i < n; i++) {
        if (degree[i] <=  1) continue;
        cur_height = BFS(i, n, graph, queue);
        if(cur_height < min_height) {
            results[0] = i;
            *returnSize = 1;
        }
        else if(cur_height == min_height) {
            results[(*returnSize)++] = i;
        }
    }

    // shrink memory
    realloc(results, (size_t)returnSize);
    free(degree);
    free(graph);
    free(queue);

    return results;
}



int main() {
    return 0;
}
