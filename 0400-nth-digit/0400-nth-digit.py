class Solution:
    def findNthDigit(self, n):
        digit_len = 1
        count = 9
        start = 1

        while n > digit_len * count:
            n -= digit_len * count
            digit_len += 1
            count *= 10
            start *= 10

        num = start + (n - 1) // digit_len
        digit_index = (n - 1) % digit_len

        return int(str(num)[digit_index])