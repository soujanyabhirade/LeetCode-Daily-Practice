class Solution:
    def areSimilar(self, mat, k):
        n = len(mat[0])
        k %= n

        for i in range(len(mat)):
            shift = k if i % 2 == 0 else -k

            for j in range(n):
                if mat[i][j] != mat[i][(j + shift) % n]:
                    return False

        return True