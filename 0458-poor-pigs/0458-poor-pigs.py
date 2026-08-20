class Solution:
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        rounds = minutesToTest // minutesToDie

        states = rounds + 1
        pigs = 0

        while states ** pigs < buckets:
            pigs += 1

        return pigs