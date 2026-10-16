class Solution:
    def sumCounts(self, nums):
        MOD = 10**9 + 7
        n = len(nums)

        tree = [0] * (4 * n)
        sq = [0] * (4 * n)
        lazy = [0] * (4 * n)

        def apply(node, l, r, v):
            length = r - l + 1

            sq[node] = (
                sq[node] + 2 * v * tree[node] + length * v * v
            ) % MOD

            tree[node] = (tree[node] + length * v) % MOD
            lazy[node] += v

        def push(node, l, r):
            if lazy[node] == 0 or l == r:
                return

            mid = (l + r) // 2
            v = lazy[node]

            apply(node * 2, l, mid, v)
            apply(node * 2 + 1, mid + 1, r, v)

            lazy[node] = 0

        def update(node, l, r, ql, qr):
            if ql <= l and r <= qr:
                apply(node, l, r, 1)
                return

            push(node, l, r)
            mid = (l + r) // 2

            if ql <= mid:
                update(node * 2, l, mid, ql, qr)

            if qr > mid:
                update(node * 2 + 1, mid + 1, r, ql, qr)

            tree[node] = (
                tree[node * 2] + tree[node * 2 + 1]
            ) % MOD

            sq[node] = (
                sq[node * 2] + sq[node * 2 + 1]
            ) % MOD

        last = {}
        ans = 0

        for i, x in enumerate(nums):
            prev = last.get(x, -1)

            update(1, 0, n - 1, prev + 1, i)

            last[x] = i
            ans = (ans + sq[1]) % MOD

        return ans