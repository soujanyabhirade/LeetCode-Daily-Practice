class Solution:
    def solveSudoku(self, board):
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]
        empty = []

        for r in range(9):
            for c in range(9):
                val = board[r][c]
                if val == '.':
                    empty.append((r, c))
                else:
                    box = (r // 3) * 3 + (c // 3)
                    rows[r].add(val)
                    cols[c].add(val)
                    boxes[box].add(val)

        def backtrack(idx):
            if idx == len(empty):
                return True
            r, c = empty[idx]
            box = (r // 3) * 3 + (c // 3)
            for digit in '123456789':
                if digit not in rows[r] and digit not in cols[c] and digit not in boxes[box]:
                    rows[r].add(digit)
                    cols[c].add(digit)
                    boxes[box].add(digit)
                    board[r][c] = digit
                    if backtrack(idx + 1):
                        return True
                    rows[r].discard(digit)
                    cols[c].discard(digit)
                    boxes[box].discard(digit)
                    board[r][c] = '.'
            return False

        backtrack(0)