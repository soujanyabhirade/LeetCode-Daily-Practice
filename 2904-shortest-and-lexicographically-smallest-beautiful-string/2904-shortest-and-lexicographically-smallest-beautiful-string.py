class Solution:
    def shortestBeautifulSubstring(self, s, k):
        n = len(s)
        best = ""

        left = 0
        ones = 0

        for right in range(n):
            if s[right] == '1':
                ones += 1

            while ones > k:
                if s[left] == '1':
                    ones -= 1
                left += 1

            if ones == k:
                while s[left] == '0':
                    left += 1

                curr = s[left:right + 1]

                if best == "" or len(curr) < len(best) or \
                   (len(curr) == len(best) and curr < best):
                    best = curr

        return best