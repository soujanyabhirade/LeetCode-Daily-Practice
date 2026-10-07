class Solution:
    def removeInvalidParentheses(self, s):
        def isValid(string):
            balance = 0

            for ch in string:
                if ch == '(':
                    balance += 1
                elif ch == ')':
                    balance -= 1

                    if balance < 0:
                        return False

            return balance == 0

        result = []
        queue = [s]
        visited = {s}
        found = False

        while queue:
            next_queue = []

            for current in queue:
                if isValid(current):
                    result.append(current)
                    found = True

            # Once we find valid strings, don't remove anything more.
            if found:
                return result

            for current in queue:
                for i in range(len(current)):
                    # Only remove parentheses, never letters
                    if current[i] not in '()':
                        continue

                    new_string = current[:i] + current[i + 1:]

                    if new_string not in visited:
                        visited.add(new_string)
                        next_queue.append(new_string)

            queue = next_queue

        return result