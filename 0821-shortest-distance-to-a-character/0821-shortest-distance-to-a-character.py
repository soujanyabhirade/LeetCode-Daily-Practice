class Solution:
    def shortestToChar(self, s, c):
        n = len(s)
        answer = [n] * n

        # Left to right
        prev = -n

        for i in range(n):
            if s[i] == c:
                prev = i

            answer[i] = i - prev

        # Right to left
        prev = 2 * n

        for i in range(n - 1, -1, -1):
            if s[i] == c:
                prev = i

            answer[i] = min(answer[i], prev - i)

        return answer