from collections import defaultdict

class Solution(object):
    def characterReplacement(self, s, k):
        count = defaultdict(int)

        left = 0
        max_freq = 0
        ans = 0

        for right in range(len(s)):
            count[s[right]] += 1

            # Maximum frequency in current window
            max_freq = max(max_freq, count[s[right]])

            # Too many replacements needed
            while (right - left + 1) - max_freq > k:
                count[s[left]] -= 1
                left += 1

            ans = max(ans, right - left + 1)

        return ans