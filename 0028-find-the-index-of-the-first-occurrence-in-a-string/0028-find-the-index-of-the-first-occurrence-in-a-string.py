class Solution:
    def strStr(self, haystack, needle):
        n = len(haystack)
        m = len(needle)

        for i in range(n - m + 1):       # only slide while a full match is possible
            if haystack[i : i + m] == needle:
                return i

        return -1