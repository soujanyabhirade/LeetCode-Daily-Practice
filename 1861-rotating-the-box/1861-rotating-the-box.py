class Solution:
    def rotateTheBox(self, boxGrid):
        m = len(boxGrid)
        n = len(boxGrid[0])

        # Make stones fall to the right
        for row in boxGrid:

            empty = n - 1

            for j in range(n - 1, -1, -1):

                if row[j] == '*':
                    empty = j - 1

                elif row[j] == '#':
                    row[j] = '.'
                    row[empty] = '#'
                    empty -= 1

        # Rotate 90 degrees clockwise
        result = []

        for j in range(n):
            new_row = []

            for i in range(m - 1, -1, -1):
                new_row.append(boxGrid[i][j])

            result.append(new_row)

        return result