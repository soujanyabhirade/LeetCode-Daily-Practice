class Solution:
    def ambiguousCoordinates(self, s):
        s = s[1:-1]

        def generate(part):
            result = []

            # No decimal point
            if len(part) == 1 or part[0] != '0':
                result.append(part)

            # Decimal point
            for i in range(1, len(part)):
                left = part[:i]
                right = part[i:]

                # Left side cannot have leading zeros
                if len(left) > 1 and left[0] == '0':
                    continue

                # Right side cannot end with zero
                if right[-1] == '0':
                    continue

                result.append(left + "." + right)

            return result

        answer = []

        # Split into left and right coordinates
        for i in range(1, len(s)):
            left = s[:i]
            right = s[i:]

            left_parts = generate(left)
            right_parts = generate(right)

            for x in left_parts:
                for y in right_parts:
                    answer.append("(" + x + ", " + y + ")")

        return answer