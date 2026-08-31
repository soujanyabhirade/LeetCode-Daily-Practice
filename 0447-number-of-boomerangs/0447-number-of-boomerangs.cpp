class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            unordered_map<long long, int> mp;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                long long dx = points[i][0] - points[j][0];
                long long dy = points[i][1] - points[j][1];

                long long dist = dx * dx + dy * dy;

                mp[dist]++;
            }

            for (auto& [dist, cnt] : mp) {
                ans += cnt * (cnt - 1);
            }
        }

        return ans;
    }
};