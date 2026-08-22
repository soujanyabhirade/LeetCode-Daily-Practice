class Solution:
    def maxChunksToSorted(self, arr):
        sorted_arr = sorted(arr)

        sum1 = 0
        sum2 = 0
        chunks = 0

        for i in range(len(arr)):
            sum1 += arr[i]
            sum2 += sorted_arr[i]

            if sum1 == sum2:
                chunks += 1

        return chunks