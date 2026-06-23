class Solution(object):
    def majorityElement(self, nums):
        # Step 1: Find potential candidates
        candidate1 = None
        candidate2 = None
        count1 = 0
        count2 = 0

        for num in nums:
            if num == candidate1:
                count1 += 1
            elif num == candidate2:
                count2 += 1
            elif count1 == 0:
                candidate1 = num
                count1 = 1
            elif count2 == 0:
                candidate2 = num
                count2 = 1
            else:
                count1 -= 1
                count2 -= 1

        # Step 2: Verify the candidates
        result = []

        if nums.count(candidate1) > len(nums) // 3:
            result.append(candidate1)

        if candidate2 != candidate1 and \
           nums.count(candidate2) > len(nums) // 3:
            result.append(candidate2)

        return result