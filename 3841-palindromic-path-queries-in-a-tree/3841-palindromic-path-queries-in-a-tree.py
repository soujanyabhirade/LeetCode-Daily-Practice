class Solution:
    def palindromePath(self, n, edges, s, queries):
        from collections import defaultdict

        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        parent = [-1] * n
        depth = [0] * n
        size = [1] * n
        heavy = [-1] * n

        order = [0]
        for u in order:
            for v in graph[u]:
                if v == parent[u]:
                    continue
                parent[v] = u
                depth[v] = depth[u] + 1
                order.append(v)

        for u in reversed(order):
            largest = 0
            for v in graph[u]:
                if parent[v] == u:
                    size[u] += size[v]
                    if size[v] > largest:
                        largest = size[v]
                        heavy[u] = v

        head = [0] * n
        pos = [0] * n
        timer = 0
        stack = [(0, 0)]

        while stack:
            u, h = stack.pop()
            while u != -1:
                head[u] = h
                pos[u] = timer
                timer += 1

                for v in graph[u]:
                    if parent[v] == u and v != heavy[u]:
                        stack.append((v, v))

                u = heavy[u]

        tree = [0] * (2 * n)
        for u in range(n):
            tree[n + pos[u]] = 1 << (ord(s[u]) - ord('a'))

        for i in range(n - 1, 0, -1):
            tree[i] = tree[2 * i] ^ tree[2 * i + 1]

        def update(p, value):
            p += n
            tree[p] = value
            p //= 2
            while p:
                tree[p] = tree[2 * p] ^ tree[2 * p + 1]
                p //= 2

        def range_xor(l, r):
            result = 0
            l += n
            r += n
            while l < r:
                if l & 1:
                    result ^= tree[l]
                    l += 1
                if r & 1:
                    r -= 1
                    result ^= tree[r]
                l //= 2
                r //= 2
            return result

        def path_xor(u, v):
            result = 0
            while head[u] != head[v]:
                if depth[head[u]] < depth[head[v]]:
                    u, v = v, u
                result ^= range_xor(pos[head[u]], pos[u] + 1)
                u = parent[head[u]]

            if depth[u] > depth[v]:
                u, v = v, u

            result ^= range_xor(pos[u], pos[v] + 1)
            return result

        answer = []

        for q in queries:
            parts = q.split()

            if parts[0] == "update":
                u = int(parts[1])
                c = parts[2]
                s = s[:u] + c + s[u + 1:]
                update(pos[u], 1 << (ord(c) - ord('a')))
            else:
                u, v = int(parts[1]), int(parts[2])
                mask = path_xor(u, v)
                answer.append(mask == 0 or (mask & (mask - 1)) == 0)

        return answer