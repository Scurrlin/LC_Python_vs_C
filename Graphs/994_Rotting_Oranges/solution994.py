from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:      
        rows = len(grid)
        if rows == 0:
            return -1
        cols = len(grid[0])
        fresh_count = 0
        rotten = deque()
        
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    rotten.append((r, c))
                elif grid[r][c] == 1:
                    fresh_count += 1
        
        minutes_passed = 0
        while rotten and fresh_count > 0:
            minutes_passed += 1
            for _ in range(len(rotten)):
                x, y = rotten.popleft()
                for dx, dy in [(1,0), (-1,0), (0,1), (0,-1)]:
                    xx, yy = x + dx, y + dy
                    if xx < 0 or xx == rows or yy < 0 or yy == cols:
                        continue
                    if grid[xx][yy] == 0 or grid[xx][yy] == 2:
                        continue                        
                    fresh_count -= 1
                    grid[xx][yy] = 2
                    rotten.append((xx, yy))

        return minutes_passed if fresh_count == 0 else -1

# Runtime1: 48ms, beats 69.18%
# Memory1: 16.58MB, beats 60.88%

# Runtime2: 42ms, beats 93.37%
# Memory2: 16.59MB, beats 60.88%

# Runtime3: 45ms, beats 84.11%
# Memory3: 16.58MB, beats 60.88%