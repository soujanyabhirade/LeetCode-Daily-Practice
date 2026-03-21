class Solution:
    def divide(self, dividend, divisor):
        INT_MAX, INT_MIN = 2**31 - 1, -(2**31)

        if dividend == INT_MIN and divisor == -1:
            return INT_MAX

        neg = (dividend < 0) != (divisor < 0)
        a, b = abs(dividend), abs(divisor)
        quotient = 0

        while a >= b:
            temp, multiple = b, 1
            while a >= (temp << 1):
                temp <<= 1
                multiple <<= 1
            a -= temp
            quotient += multiple

        return -quotient if neg else quotient