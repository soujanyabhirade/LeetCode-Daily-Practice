class Solution:
    def maxChunksToSorted(self, arr):
        max_val = 0
        chunks = 0

        for i in range(len(arr)):
            max_val = max(max_val, arr[i])

            if max_val == i:
                chunks += 1

        return chunks