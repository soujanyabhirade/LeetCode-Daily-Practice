class Solution:
    def lexGreaterPermutation(self, s, target):
        n = len(s)

        # Frequency of characters in s
        original = [0] * 26

        for ch in s:
            original[ord(ch) - ord('a')] += 1

        # Try every position from right to left
        for i in range(n - 1, -1, -1):

            # Copy frequencies
            count = original[:]

            # Use characters required by target[0:i]
            possible = True

            for j in range(i):
                x = ord(target[j]) - ord('a')

                if count[x] == 0:
                    possible = False
                    break

                count[x] -= 1

            if not possible:
                continue

            # Find smallest character > target[i]
            x = ord(target[i]) - ord('a')

            bigger = -1

            for c in range(x + 1, 26):
                if count[c] > 0:
                    bigger = c
                    break

            if bigger == -1:
                continue

            # We found the position where we become greater
            count[bigger] -= 1

            result = target[:i]
            result += chr(bigger + ord('a'))

            # Add remaining characters in sorted order
            for c in range(26):
                result += chr(c + ord('a')) * count[c]

            return result

        return ""