class Solution:
    def longestValidParentheses(self, s):
        # Stack holds indices of unmatched characters
        # Seed with -1 as the base boundary
        stack = [-1]
        max_len = 0

        for i, ch in enumerate(s):
            if ch == '(':
                stack.append(i)
            else:
                stack.pop()
                if stack:
                    # Distance from current index to last unmatched boundary
                    max_len = max(max_len, i - stack[-1])
                else:
                    # No boundary left — current ')' becomes the new boundary
                    stack.append(i)

        return max_len