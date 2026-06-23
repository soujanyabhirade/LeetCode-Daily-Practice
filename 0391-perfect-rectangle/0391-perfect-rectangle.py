class Solution(object):
    def isRectangleCover(self, rectangles):
        corners = set()
        total_area = 0

        min_x = float('inf')
        min_y = float('inf')
        max_x = float('-inf')
        max_y = float('-inf')

        for x1, y1, x2, y2 in rectangles:
            # Update bounding rectangle
            min_x = min(min_x, x1)
            min_y = min(min_y, y1)
            max_x = max(max_x, x2)
            max_y = max(max_y, y2)

            # Add area
            total_area += (x2 - x1) * (y2 - y1)

            # Process four corners
            for corner in [(x1, y1), (x1, y2),
                           (x2, y1), (x2, y2)]:

                if corner in corners:
                    corners.remove(corner)
                else:
                    corners.add(corner)

        expected_corners = {
            (min_x, min_y),
            (min_x, max_y),
            (max_x, min_y),
            (max_x, max_y)
        }

        # Must have exactly four outer corners
        if corners != expected_corners:
            return False

        # Areas must match
        expected_area = (max_x - min_x) * (max_y - min_y)

        return total_area == expected_area