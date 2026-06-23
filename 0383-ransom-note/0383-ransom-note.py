from collections import Counter

class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        count = Counter(magazine)

        for ch in ransomNote:
            if count[ch] == 0:
                return False
            count[ch] -= 1

        return True