class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        // Store all indices for each value
        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        vector<int> answer;

        for (int q : queries) {
            int value = nums[q];
            vector<int>& v = pos[value];

            // Only one occurrence
            if (v.size() == 1) {
                answer.push_back(-1);
                continue;
            }

            // Find position of q in the list
            int idx = lower_bound(v.begin(), v.end(), q) - v.begin();

            // Previous occurrence
            int prev = v[(idx - 1 + v.size()) % v.size()];

            // Next occurrence
            int next = v[(idx + 1) % v.size()];

            int d1 = abs(q - prev);
            int d2 = abs(q - next);

            // Circular distance
            d1 = min(d1, n - d1);
            d2 = min(d2, n - d2);

            answer.push_back(min(d1, d2));
        }

        return answer;
    }
};