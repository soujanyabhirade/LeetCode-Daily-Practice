class Solution:
    def expressiveWords(self, s, words):
        def check(word):
            i = 0
            j = 0

            while i < len(s) and j < len(word):
                if s[i] != word[j]:
                    return False

                # Count group in s
                start_i = i
                while i < len(s) and s[i] == s[start_i]:
                    i += 1
                count_s = i - start_i

                # Count group in word
                start_j = j
                while j < len(word) and word[j] == word[start_j]:
                    j += 1
                count_w = j - start_j

                # Check whether this group can be stretched
                if count_s < count_w:
                    return False

                if count_s != count_w and count_s < 3:
                    return False

            # Both strings must be completely consumed
            return i == len(s) and j == len(word)

        count = 0

        for word in words:
            if check(word):
                count += 1

        return count