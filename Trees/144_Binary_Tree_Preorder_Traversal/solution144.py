class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        curr, stack = root, []
        res = []
        while curr or stack:
            if curr:
                res.append(curr.val)
                stack.append(curr.right)
                curr = curr.left
            else:
                curr = stack.pop()
        return res

# Runtime1: 32ms, beats 75.35%
# Memory1: 16.48MB, beats 71.07%

# Runtime2: 26ms, beats 96.30%
# Memory2: 16.56MB, beats 22.17%

# Runtime3: 20ms, beats 99.66%
# Memory3: 16.57MB, beats 22.17%