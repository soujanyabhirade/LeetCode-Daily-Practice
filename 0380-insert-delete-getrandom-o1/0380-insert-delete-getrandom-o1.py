import random

class RandomizedSet(object):

    def __init__(self):
        self.nums = []          # Stores values
        self.pos = {}           # value -> index

    def insert(self, val):
        if val in self.pos:
            return False

        self.pos[val] = len(self.nums)
        self.nums.append(val)

        return True

    def remove(self, val):
        if val not in self.pos:
            return False

        idx = self.pos[val]
        last = self.nums[-1]

        # Move last element to deleted spot
        self.nums[idx] = last
        self.pos[last] = idx

        # Remove last element
        self.nums.pop()
        del self.pos[val]

        return True

    def getRandom(self):
        return random.choice(self.nums)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()