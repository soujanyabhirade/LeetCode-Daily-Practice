class Solution:
    def customSortString(self, order, s):
        count = {}

        # Count characters in s
        for ch in s:
            count[ch] = count.get(ch, 0) + 1

        ans = []

        # Add characters according to order
        for ch in order:
            if ch in count:
                ans.append(ch * count[ch])
                del count[ch]

        # Add remaining characters
        for ch in count:
            ans.append(ch * count[ch])

        return "".join(ans)