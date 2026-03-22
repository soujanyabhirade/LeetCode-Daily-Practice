class Solution:
    def search(self, nums, target):
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = (left + right) // 2

            if nums[mid] == target:
                return True

            # Can't determine which side is sorted — shrink boundaries
            if nums[left] == nums[mid] == nums[right]:
                left += 1
                right -= 1

            # Left half is sorted
            elif nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1  # target in left half
                else:
                    left = mid + 1   # target in right half

            # Right half is sorted
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1   # target in right half
                else:
                    right = mid - 1  # target in left half

        return False