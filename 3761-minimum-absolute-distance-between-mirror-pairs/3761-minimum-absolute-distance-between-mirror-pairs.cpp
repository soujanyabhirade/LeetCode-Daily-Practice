class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;

        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> last;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            // Check if current number is the reverse
            // of any previous number
            if (last.find(nums[i]) != last.end()) {
                ans = min(ans, i - last[nums[i]]);
            }

            // Store reverse of current number
            int rev = reverseNum(nums[i]);
            last[rev] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};