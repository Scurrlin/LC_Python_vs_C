#include <stdio.h>

void dfs(char** grid, int gridSize, int* gridColSize, int i, int j);

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0) return 0;
    
    int num_islands = 0;

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridColSize[i]; ++j) {
            if (grid[i][j] == '1') {
                num_islands++;
                dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }

    return num_islands;
}

void dfs(char** grid, int gridSize, int* gridColSize, int i, int j) {
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize[i] || grid[i][j] != '1') {
        return;
    }

    grid[i][j] = '0';

    dfs(grid, gridSize, gridColSize, i + 1, j);
    dfs(grid, gridSize, gridColSize, i - 1, j);
    dfs(grid, gridSize, gridColSize, i, j + 1);
    dfs(grid, gridSize, gridColSize, i, j - 1);
}

// Runtime1: 26ms, beats 24.37%
// Memory1: 11.62MB, beats 63.35%

// Runtime2: 26ms, beats 24.37%
// Memory2: 11.79MB, beats 50.29%

// Runtime3: 22ms, beats 57.50%
// Memory3: 11.50MB, beats 98.64%

// Runtime reduced by a factor of 10 to not skew data visualization