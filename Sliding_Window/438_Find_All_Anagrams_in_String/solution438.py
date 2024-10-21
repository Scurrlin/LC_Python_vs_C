class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        
        startIndex = 0
        pMap, sMap = {}, {}
        res = []
        
        for char in p:
            pMap[char] = 1 + pMap.get(char, 0)
        
        for i in range(len(s)):
            sMap[s[i]] = 1 + sMap.get(s[i], 0)

            if i >= len(p) - 1:
                if sMap == pMap:
                    res.append(startIndex)
                
                if s[startIndex] in sMap:
                    sMap[s[startIndex]] -= 1
                    if sMap[s[startIndex]] == 0:
                        del sMap[s[startIndex]]
                startIndex += 1
        
        return res

# Runtime1: 89ms, beats 62.35%
# Memory1: 17.57MB, beats 96.49%

# Runtime2: 98ms, beats 52%
# Memory2: 17.62MB, beats 83.55%

# Runtime3: 77ms, beats 83.43%
# Memory3: 17.50MB, beats 99.60%