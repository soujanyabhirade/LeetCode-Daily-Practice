class Solution:
    def mostCommonWord(self, paragraph, banned):
        # Convert to lowercase
        paragraph = paragraph.lower()

        # Replace punctuation with spaces
        for ch in "!?',;.":
            paragraph = paragraph.replace(ch, " ")

        # Convert banned list to a set
        banned = set(banned)

        # Count words
        count = {}

        for word in paragraph.split():
            if word not in banned:
                count[word] = count.get(word, 0) + 1

        # Find most frequent word
        answer = ""
        max_count = 0

        for word in count:
            if count[word] > max_count:
                max_count = count[word]
                answer = word

        return answer