class Solution:
    def exclusiveTime(self, n, logs):
        ans = [0] * n
        stack = []
        prev_time = 0

        for log in logs:
            fid, typ, time = log.split(":")
            fid = int(fid)
            time = int(time)

            if typ == "start":
                # Current function gets the time since prev_time
                if stack:
                    ans[stack[-1]] += time - prev_time

                stack.append(fid)
                prev_time = time

            else:  # end
                # +1 because end timestamp is inclusive
                ans[stack.pop()] += time - prev_time + 1

                prev_time = time + 1

        return ans