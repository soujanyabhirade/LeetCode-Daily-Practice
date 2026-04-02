
class Solution:
    def cloneGraph(self, node):
        if not node:
            return None

        visited = {}

        def dfs(n):
            if n in visited:
                return visited[n]
            clone = Node(n.val)
            visited[n] = clone
            for neighbor in n.neighbors:
                clone.neighbors.append(dfs(neighbor))
            return clone

        return dfs(node)
        