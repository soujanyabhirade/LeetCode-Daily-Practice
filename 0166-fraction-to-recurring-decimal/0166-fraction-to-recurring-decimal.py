class Solution:
    def fractionToDecimal(self, numerator, denominator):
        if numerator == 0:
            return "0"

        # Determine the sign
        negative = (numerator < 0) != (denominator < 0)

        numerator = abs(numerator)
        denominator = abs(denominator)

        # Integer part
        integer_part = numerator // denominator
        remainder = numerator % denominator

        result = ""

        if negative:
            result += "-"

        result += str(integer_part)

        # No fractional part
        if remainder == 0:
            return result

        result += "."

        # remainder -> position in result
        seen = {}

        while remainder != 0:
            if remainder in seen:
                pos = seen[remainder]
                result = result[:pos] + "(" + result[pos:] + ")"
                break

            seen[remainder] = len(result)

            remainder *= 10
            digit = remainder // denominator
            remainder %= denominator

            result += str(digit)

        return result