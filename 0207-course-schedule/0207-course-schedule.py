class Solution:
    def canFinish(self, numCourses, prerequisites):
        graph = [[] for _ in range(numCourses)]
        for a, b in prerequisites:
            graph[b].append(a)

        # 0 = unvisited, 1 = visiting, 2 = visited
        state = [0] * numCourses

        def dfs(node):
            if state[node] == 1:
                return False
            if state[node] == 2:
                return True
            state[node] = 1
            for neighbor in graph[node]:
                if not dfs(neighbor):
                    return False
            state[node] = 2
            return True

        for i in range(numCourses):
            if not dfs(i):
                return False

        return True