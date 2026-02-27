class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""

        common_prefix = ""

        strs.sort()
        first_str = strs[0]
        last_str = strs[-1]

        for i in range(0,len(first_str)):
            if first_str[i] == last_str[i]:
                common_prefix = common_prefix + first_str[i]
            else:
                break



        return common_prefix
                