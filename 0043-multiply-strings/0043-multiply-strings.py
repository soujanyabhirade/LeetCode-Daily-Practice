class Solution:
    def multiply(self, num1, num2):
        m, n = len(num1), len(num2)
        pos = [0] * (m + n)  # at most m+n digits in result

        # Work right to left on both numbers
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                mul = (ord(num1[i]) - ord('0')) * (ord(num2[j]) - ord('0'))

                p1, p2 = i + j, i + j + 1      # p1 = carry pos, p2 = result pos
                total = mul + pos[p2]           # add to existing value at p2

                pos[p2] = total % 10            # remainder stays at p2
                pos[p1] += total // 10          # carry goes to p1

        # Strip leading zeros and build result string
        result = ''.join(str(d) for d in pos).lstrip('0')
        return result if result else '0'