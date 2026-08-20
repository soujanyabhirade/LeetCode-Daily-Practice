class Solution:
    def numberOfBoomerangs(self, points):
        result = 0

        for i in range(len(points)):
            count = {}

            for j in range(len(points)):
                if i == j:
                    continue

                dx = points[i][0] - points[j][0]
                dy = points[i][1] - points[j][1]

                distance = dx * dx + dy * dy

                count[distance] = count.get(distance, 0) + 1

            for freq in count.values():
                result += freq * (freq - 1)

        return result