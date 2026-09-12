class Solution {
public:
    struct State {
        long long score;
        vector<int> ids;

        State() {
            score = 0;
        }

        State(long long s, vector<int> v) {
            score = s;
            ids = v;
        }
    };

    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {left, right, weight, original index}
        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        // Sort by ending position
        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x[1] != y[1])
                return x[1] < y[1];

            return x[3] < y[3];
        });

        // Right endpoints
        vector<long long> rights(n);

        for (int i = 0; i < n; i++)
            rights[i] = a[i][1];

        // prev[i] = number of intervals before i
        // whose right < current left
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            prev[i] =
                lower_bound(rights.begin(),
                            rights.begin() + i,
                            a[i][0])
                - rights.begin();
        }

        // dp[i][k]:
        // best answer using first i intervals
        // and choosing at most k intervals
        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = 1; i <= n; i++) {
            // Option 1: don't take current interval
            for (int k = 0; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];
            }

            // Option 2: take current interval
            int idx = i - 1;

            for (int k = 1; k <= 4; k++) {

                State candidate = dp[prev[idx]][k - 1];

                candidate.score += a[idx][2];
                candidate.ids.push_back((int)a[idx][3]);

                // Lexicographic comparison needs sorted indices
                sort(candidate.ids.begin(), candidate.ids.end());

                if (better(candidate, dp[i][k])) {
                    dp[i][k] = candidate;
                }
            }
        }

        return dp[n][4].ids;
    }
};