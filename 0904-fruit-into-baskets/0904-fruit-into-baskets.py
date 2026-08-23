class Solution:
    def totalFruit(self, fruits):
        left = 0
        count = {}
        ans = 0

        for right in range(len(fruits)):
            # Add current fruit
            count[fruits[right]] = count.get(fruits[right], 0) + 1

            # More than 2 fruit types
            while len(count) > 2:
                count[fruits[left]] -= 1

                if count[fruits[left]] == 0:
                    del count[fruits[left]]

                left += 1

            # Current window has at most 2 types
            ans = max(ans, right - left + 1)

        return ans