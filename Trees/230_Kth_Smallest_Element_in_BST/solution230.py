class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        stack = []
        curr = root

        while stack or curr:
            while curr:
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            k -= 1
            if k == 0:
                return curr.val
            curr = curr.right
            
# Runtime1: 40ms, beats 83.55%
# Memory1: 19.40MB, beats 97.80%

# Runtime2: 33ms, beats 97.90%
# Memory2: 19.48MB, beats 76.97%

# Runtime3: 35ms, beats 96.12%
# Memory3: 19.48MB, beats 76.97%