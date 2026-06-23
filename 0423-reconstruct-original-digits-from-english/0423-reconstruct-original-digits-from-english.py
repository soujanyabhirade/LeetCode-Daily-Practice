from collections import Counter

class Solution(object):
    def originalDigits(self, s):
        count = Counter(s)
        digits = [0] * 10

        # Digits with unique identifying letters
        digits[0] = count['z']  # zero
        digits[2] = count['w']  # two
        digits[4] = count['u']  # four
        digits[6] = count['x']  # six
        digits[8] = count['g']  # eight

        # Remaining digits
        digits[3] = count['h'] - digits[8]          # three
        digits[5] = count['f'] - digits[4]          # five
        digits[7] = count['s'] - digits[6]          # seven
        digits[1] = count['o'] - digits[0] - digits[2] - digits[4]
        digits[9] = count['i'] - digits[5] - digits[6] - digits[8]

        result = []

        for digit in range(10):
            result.append(str(digit) * digits[digit])

        return "".join(result)