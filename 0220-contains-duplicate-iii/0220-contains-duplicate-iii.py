class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, indexDiff, valueDiff):
        if valueDiff < 0:
            return False

        buckets = {}
        width = valueDiff + 1  # bucket size

        for i, num in enumerate(nums):
            # Correct bucket ID handling for both positive and negative numbers
            bucket_id = num // width

            # Same bucket
            if bucket_id in buckets:
                return True

            # Check adjacent buckets
            if (bucket_id - 1 in buckets and
                    abs(num - buckets[bucket_id - 1]) <= valueDiff):
                return True

            if (bucket_id + 1 in buckets and
                    abs(num - buckets[bucket_id + 1]) <= valueDiff):
                return True

            buckets[bucket_id] = num

            # Maintain sliding window of size indexDiff
            if i >= indexDiff:
                old_bucket = nums[i - indexDiff] // width
                del buckets[old_bucket]

        return False