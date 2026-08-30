class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int, int>> st;

        for (auto &p : points) {
            st.insert({p[0], p[1]});
        }

        int ans = INT_MAX;

        int n = points.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                // They must have different x and y coordinates
                if (x1 == x2 || y1 == y2)
                    continue;

                // Other two corners
                if (st.count({x1, y2}) && st.count({x2, y1})) {
                    int area = abs(x1 - x2) * abs(y1 - y2);
                    ans = min(ans, area);
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};