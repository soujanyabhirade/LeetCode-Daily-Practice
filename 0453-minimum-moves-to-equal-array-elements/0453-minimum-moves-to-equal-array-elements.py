class Solution:
    def minMoves(self, nums):
        minimum = min(nums)
        moves = 0

        for num in nums:
            moves += num - minimum

        return moves
        