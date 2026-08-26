class Solution:
    def minimumLengthEncoding(self, words):
        # Put all words into a set
        words = set(words)

        # Remove words that are suffixes of another word
        for word in list(words):
            for i in range(1, len(word)):
                suffix = word[i:]

                if suffix in words:
                    words.remove(suffix)

        # Every remaining word needs its own word + '#'
        answer = 0

        for word in words:
            answer += len(word) + 1

        return answer