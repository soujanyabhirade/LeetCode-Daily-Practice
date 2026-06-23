from collections import Counter

class Solution(object):
    def firstUniqChar(self, s):
        count = Counter(s)

        for i, ch in enumerate(s):
            if count[ch] == 1:
                return i

        return -1