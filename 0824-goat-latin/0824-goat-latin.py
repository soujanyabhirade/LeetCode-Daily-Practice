class Solution:
    def toGoatLatin(self, sentence):
        vowels = "aeiouAEIOU"
        words = sentence.split()

        result = []

        for i, word in enumerate(words, 1):

            # If the word starts with a consonant
            if word[0] not in vowels:
                word = word[1:] + word[0]

            # Add "ma" + i number of 'a's
            word += "ma" + "a" * i

            result.append(word)

        return " ".join(result)
        