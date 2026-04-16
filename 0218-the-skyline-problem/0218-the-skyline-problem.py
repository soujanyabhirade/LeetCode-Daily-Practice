import heapq

class Solution:
    def getSkyline(self, buildings):
        events = []
        for left, right, height in buildings:
            events.append((left, -height, right))
            events.append((right, 0, 0))

        events.sort()

        result = []
        heap = [(0, float('inf'))]
        prev_max_height = 0

        for x, neg_h, right in events:
            if neg_h != 0:
                heapq.heappush(heap, (neg_h, right))

            while heap[0][1] <= x:
                heapq.heappop(heap)

            curr_max_height = -heap[0][0]

            if curr_max_height != prev_max_height:
                result.append([x, curr_max_height])
                prev_max_height = curr_max_height

        return result