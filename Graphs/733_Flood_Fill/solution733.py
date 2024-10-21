class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        
        start_color = image[sr][sc]
        
        def flood_fill(x, y):
            if x < 0 or x >= len(image): return
            if y < 0 or y >= len(image[0]): return
            
            if image[x][y] == color: return
            if image[x][y] != start_color: return
            
            image[x][y] = color
            
            flood_fill(x-1, y)
            flood_fill(x+1, y)
            flood_fill(x, y+1)
            flood_fill(x, y-1)
        
        flood_fill(sr, sc)
        return image

# Runtime1: 64ms, beats 74.66%
# Memory1: 17MB, beats 5.87%

# Runtime2: 64ms, beats 74.80%
# Memory2: 16.92MB, beats 6.29%

# Runtime3: 62ms, beats 83.67%
# Memory3: 16.86MB, beats 22.46%