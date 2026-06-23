import random
from collections import defaultdict

class RandomizedCollection(object):

    def __init__(self):
        self.nums = []
        self.indices = defaultdict(set)

    def insert(self, val):
        is_new = len(self.indices[val]) == 0

        self.nums.append(val)
        self.indices[val].add(len(self.nums) - 1)

        return is_new

    def remove(self, val):
        if not self.indices[val]:
            return False

        # Get an index of val to remove
        remove_idx = self.indices[val].pop()

        last_val = self.nums[-1]
        last_idx = len(self.nums) - 1

        # Move last element to remove_idx if needed
        if remove_idx != last_idx:
            self.nums[remove_idx] = last_val

            self.indices[last_val].remove(last_idx)
            self.indices[last_val].add(remove_idx)

        # Remove last element
        self.nums.pop()

        return True

    def getRandom(self):
        return random.choice(self.nums)


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()