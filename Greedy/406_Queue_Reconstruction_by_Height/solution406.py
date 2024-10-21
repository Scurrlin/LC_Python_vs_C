class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key = lambda x: (-x[0], x[1]))
        queue = []
        for person in people: 
            queue.insert(person[1], person)
        return queue

# Runtime1: 76ms, beats 93.18%
# Memory1: 17.19MB, beats 52.56%

# Runtime2: 80ms, beats 81.20%
# Memory2: 17.08MB, beats 83.14%

# Runtime3: 78ms, beats 86.58%
# Memory3: 17.08MB, beats 83.14%