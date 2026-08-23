class Solution:
    def areSimilar(self, mat, k):
        m = len(mat)
        n = len(mat[0])

        k %= n

        for i in range(m):
            if i % 2 == 0:
                # Even row: left shift
                shifted = mat[i][k:] + mat[i][:k]
            else:
                # Odd row: right shift
                shifted = mat[i][-k:] + mat[i][:-k]

            if shifted != mat[i]:
                return False

        return True