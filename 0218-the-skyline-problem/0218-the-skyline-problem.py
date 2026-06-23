import heapq

class Solution(object):
    def getSkyline(self, buildings):
        # Create events
        events = []
        for left, right, height in buildings:
            events.append((left, -height, right))
            events.append((right, 0, 0))

        # Sort by x-coordinate, then height
        events.sort()

        result = []
        # Heap stores (-height, end)
        heap = [(0, float('inf'))]

        for x, neg_h, right in events:

            # Remove buildings that have ended
            while heap and heap[0][1] <= x:
                heapq.heappop(heap)

            # Add new building if it is a start event
            if neg_h:
                heapq.heappush(heap, (neg_h, right))

            current_height = -heap[0][0]

            # Add key point if height changes
            if not result or result[-1][1] != current_height:
                result.append([x, current_height])

        return result