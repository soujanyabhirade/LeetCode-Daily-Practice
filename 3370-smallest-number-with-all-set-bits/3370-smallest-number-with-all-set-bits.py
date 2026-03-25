class Solution:
    def smallestNumber(self, n):
        x = 1
        while x < n:
            x = (x << 1) | 1
        return x