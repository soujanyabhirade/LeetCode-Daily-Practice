class Solution:
    def buildArray(self, target, n):
        ans = []
        j = 0  # points to next target element

        for num in range(1, n + 1):

            # We don't need any more numbers
            if j == len(target):
                break

            ans.append("Push")

            if num == target[j]:
                # Keep it
                j += 1
            else:
                # Remove it
                ans.append("Pop")

        return ans