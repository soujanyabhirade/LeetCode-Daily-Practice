class Solution:
    def isValid(self, s):
        stack = []
        pairs = {')': '(', '}': '{', ']': '['}

        for ch in s:
            if ch not in pairs:
                stack.append(ch)
            elif not stack or stack[-1] != pairs[ch]:
                return False
            else:
                stack.pop()

        return not stack