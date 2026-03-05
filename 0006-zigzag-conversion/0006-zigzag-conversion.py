class Solution:
    def convert(self, s, numRows):
        if numRows == 1 or numRows >= len(s):
            return s
        
        rows = [""] * numRows
        cur = 0
        step = 1
        
        for c in s:
            rows[cur] += c
            if cur == 0:
                step = 1
            elif cur == numRows - 1:
                step = -1
            cur += step
        
        return "".join(rows)