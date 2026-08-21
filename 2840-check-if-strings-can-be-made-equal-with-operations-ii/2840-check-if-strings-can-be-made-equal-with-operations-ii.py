class Solution:
    def checkStrings(self, s1, s2):
        even1 = [0] * 26
        even2 = [0] * 26

        odd1 = [0] * 26
        odd2 = [0] * 26

        for i in range(len(s1)):
            if i % 2 == 0:
                even1[ord(s1[i]) - ord('a')] += 1
                even2[ord(s2[i]) - ord('a')] += 1
            else:
                odd1[ord(s1[i]) - ord('a')] += 1
                odd2[ord(s2[i]) - ord('a')] += 1

        return even1 == even2 and odd1 == odd2