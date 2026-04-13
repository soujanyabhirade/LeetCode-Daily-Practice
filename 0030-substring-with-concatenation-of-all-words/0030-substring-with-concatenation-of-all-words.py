from collections import Counter

class Solution:
    def findSubstring(self, s, words):
        if not s or not words:
            return []

        word_len = len(words[0])
        word_count = len(words)
        total_len = word_len * word_count
        word_freq = Counter(words)
        result = []

        for offset in range(word_len):
            left = offset
            curr_freq = Counter()
            matched = 0

            for right in range(offset, len(s) - word_len + 1, word_len):
                word = s[right:right + word_len]

                if word in word_freq:
                    curr_freq[word] += 1
                    if curr_freq[word] == word_freq[word]:
                        matched += 1

                    while curr_freq[word] > word_freq[word]:
                        left_word = s[left:left + word_len]
                        if curr_freq[left_word] == word_freq[left_word]:
                            matched -= 1
                        curr_freq[left_word] -= 1
                        left += word_len

                    if matched == len(word_freq):
                        result.append(left)

                else:
                    curr_freq.clear()
                    matched = 0
                    left = right + word_len

        return result