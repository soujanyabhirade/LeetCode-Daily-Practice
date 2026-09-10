class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;

        // {sum, index in nums1, index in nums2}
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        int n = nums1.size();
        int m = nums2.size();

        // Start with nums2[0] for the first k elements of nums1
        for (int i = 0; i < min(k, n); i++) {
            pq.push({(long long)nums1[i] + nums2[0], i, 0});
        }

        while (k-- > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});

            // Move to the next element in nums2
            if (j + 1 < m) {
                pq.push({
                    (long long)nums1[i] + nums2[j + 1],
                    i,
                    j + 1
                });
            }
        }

        return ans;
    }
};