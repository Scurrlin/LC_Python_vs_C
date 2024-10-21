class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:

        output = []
        def inorder(root):
            if root is None:
                return
            inorder(root.left)
            output.append(root.val)
            inorder(root.right)
        inorder(root)
        return output

# Runtime1: 32ms, beats 75.77%
# Memory1: 16.59MB, beats 21.32%

# Runtime2: 28ms, beats 91.64%
# Memory2: 16.51MB, beats 21.32%

# Runtime3: 33ms, beats 71.29%
# Memory3: 16.62MB, beats 21.32%