class Solution:
    def countAndSay(self, n):
        result = "1"

        for _ in range(n - 1):
            curr = ""
            i = 0
            while i < len(result):
                count = 1
                while i + count < len(result) and result[i + count] == result[i]:
                    count += 1
                curr += str(count) + result[i]
                i += count
            result = curr

        return result