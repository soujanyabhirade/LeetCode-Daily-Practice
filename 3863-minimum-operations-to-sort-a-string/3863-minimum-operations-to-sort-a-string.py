class Solution:
    def minOperations(self, s):
        n = len(s)

        if s == ''.join(sorted(s)):
            return 0

        if n == 2:
            return -1

        first = s[0]
        last = s[-1]
        smallest = min(s)
        largest = max(s)

        if first == smallest or last == largest:
            return 1

        if first == largest and last == smallest:
            if s.count(largest) > 1 or s.count(smallest) > 1:
                return 2
            return 3

        return 2