from collections import Counter

class Solution(object):
    def longestPalindrome(self, s):
        count = Counter(s)

        length = 0
        odd_found = False

        for freq in count.values():
            if freq % 2 == 0:
                length += freq
            else:
                length += freq - 1
                odd_found = True

        # One odd character can be placed in the center
        if odd_found:
            length += 1

        return length