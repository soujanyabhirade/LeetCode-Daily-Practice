class Solution:
    def makeLargestSpecial(self, s):
        parts = []
        count = 0
        start = 0

        # Split into primitive special strings
        for i, ch in enumerate(s):
            if ch == '1':
                count += 1
            else:
                count -= 1

            if count == 0:
                # Remove outer 1 and 0
                inner = s[start + 1:i]

                # Recursively make the inside largest
                inner = self.makeLargestSpecial(inner)

                parts.append("1" + inner + "0")
                start = i + 1

        # Put the largest special substrings first
        parts.sort(reverse=True)

        return "".join(parts)