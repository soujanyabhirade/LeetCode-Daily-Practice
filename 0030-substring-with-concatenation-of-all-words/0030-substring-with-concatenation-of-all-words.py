from collections import Counter, defaultdict

class Solution(object):
    def findSubstring(self, s, words):
        if not s or not words:
            return []

        word_len = len(words[0])
        word_count = len(words)
        total_len = word_len * word_count

        target = Counter(words)
        result = []

        # Try all possible starting offsets
        for offset in range(word_len):
            left = offset
            current = defaultdict(int)
            count = 0

            for right in range(offset, len(s) - word_len + 1, word_len):
                word = s[right:right + word_len]

                if word in target:
                    current[word] += 1
                    count += 1

                    # Too many occurrences of this word
                    while current[word] > target[word]:
                        left_word = s[left:left + word_len]
                        current[left_word] -= 1
                        count -= 1
                        left += word_len

                    # Found a valid window
                    if count == word_count:
                        result.append(left)

                        left_word = s[left:left + word_len]
                        current[left_word] -= 1
                        count -= 1
                        left += word_len

                else:
                    # Reset window
                    current.clear()
                    count = 0
                    left = right + word_len

        return result