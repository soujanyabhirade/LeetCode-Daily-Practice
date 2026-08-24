class Solution:
    def findTheString(self, lcp):
        n = len(lcp)

        # 1. Basic validation
        for i in range(n):
            # lcp[i][i] must be the length of word[i:]
            if lcp[i][i] != n - i:
                return ""

            for j in range(n):
                # LCP can never be greater than either suffix length
                if lcp[i][j] > min(n - i, n - j):
                    return ""

                # LCP is symmetric
                if lcp[i][j] != lcp[j][i]:
                    return ""

        # 2. Assign characters
        word = [''] * n
        next_char = 0

        for i in range(n):
            if word[i] != '':
                continue

            if next_char == 26:
                return ""

            # All j with lcp[i][j] > 0 must have the same character
            for j in range(n):
                if lcp[i][j] > 0:
                    if word[j] != '':
                        # It must already have the same character
                        if word[j] != chr(ord('a') + next_char):
                            return ""
                    else:
                        word[j] = chr(ord('a') + next_char)

            next_char += 1

        word = ''.join(word)

        # 3. Validate that the constructed word
        #    produces exactly the given LCP matrix
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):

                if word[i] == word[j]:
                    expected = 1

                    if i + 1 < n and j + 1 < n:
                        expected += lcp[i + 1][j + 1]

                    if lcp[i][j] != expected:
                        return ""
                else:
                    if lcp[i][j] != 0:
                        return ""

        return word