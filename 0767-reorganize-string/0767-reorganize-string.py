import heapq
from collections import Counter

class Solution:
    def reorganizeString(self, s):
        freq = Counter(s)

        # Max heap using negative frequency
        heap = [(-count, ch) for ch, count in freq.items()]
        heapq.heapify(heap)

        result = []
        prev_count = 0
        prev_char = ""

        while heap:
            count, ch = heapq.heappop(heap)

            # If this character is same as previous,
            # we cannot use it right now.
            if ch == prev_char:
                if not heap:
                    return ""

                count2, ch2 = heapq.heappop(heap)

                result.append(ch2)
                count2 += 1

                if count2 < 0:
                    heapq.heappush(heap, (count2, ch2))

                # Put previous character back
                heapq.heappush(heap, (count, ch))

                prev_char = ch2

            else:
                result.append(ch)

                count += 1
                if count < 0:
                    heapq.heappush(heap, (count, ch))

                prev_char = ch

        return "".join(result)