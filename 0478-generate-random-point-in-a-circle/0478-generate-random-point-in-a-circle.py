import random

class Solution:

    def __init__(self, radius, x_center, y_center):
        self.r = radius
        self.x = x_center
        self.y = y_center

    def randPoint(self):
        while True:
            x = random.uniform(-self.r, self.r)
            y = random.uniform(-self.r, self.r)

            if x * x + y * y <= self.r * self.r:
                return [self.x + x, self.y + y]