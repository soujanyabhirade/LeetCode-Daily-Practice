from collections import Counter

class Solution(object):
    def longestSubstring(self, s, k):
        if len(s) < k:
            return 0

        count = Counter(s)

        # Find a character that appears less than k times
        for ch in count:
            if count[ch] < k:
                # Split on this invalid character
                return max(self.longestSubstring(part, k)
                           for part in s.split(ch))

        # All characters appear at least k times
        return len(s)