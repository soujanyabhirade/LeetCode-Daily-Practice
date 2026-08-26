class Solution:
    def uniqueLetterString(self, s):
        last = [-1] * 26
        second_last = [-1] * 26

        ans = 0

        for i in range(len(s)):
            x = ord(s[i]) - ord('A')

            # Add contribution of previous occurrence
            ans += (i - last[x]) * (last[x] - second_last[x])

            # Move positions
            second_last[x] = last[x]
            last[x] = i

        # Add contribution of the last occurrence
        n = len(s)

        for x in range(26):
            ans += (n - last[x]) * (last[x] - second_last[x])

        return ans