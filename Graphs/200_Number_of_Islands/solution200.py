class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        def dfs(i, j):
            if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] != '1':
                return
            grid[i][j] = '0'
            dfs(i+1, j)
            dfs(i-1, j)
            dfs(i, j+1)
            dfs(i, j-1)
        
        num_islands = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    num_islands += 1
                    dfs(i, j)
        
        return num_islands

# Runtime1: 226ms, beats 88.66%
# Memory1: 18.98MB, beats 62.39%

# Runtime2: 227ms, beats 87.25%
# Memory2: 19.00MB, beats 62.39%

# Runtime3: 240ms, beats 64.83%
# Memory3: 18.80MB, beats 96.14%

# Runtime reduced by a factor of 10 to not skew data visualization