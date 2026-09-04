class Solution {
public:
    int dist(int a, int b) {
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;

        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        const int INF = 1e9;

        // dp[other] = minimum cost where:
        // one finger is at the previous character
        // and the other finger is at 'other'
        vector<int> dp(27, INF);

        // Initially the two fingers can be anywhere for free.
        // We start by typing the first character.
        int first = word[0] - 'A';
        dp[26] = 0;   // 26 means finger is not placed yet

        int prev = first;

        for (int i = 1; i < word.size(); i++) {
            int cur = word[i] - 'A';

            vector<int> ndp(27, INF);

            for (int other = 0; other <= 26; other++) {
                if (dp[other] == INF)
                    continue;

                // Finger at 'prev' types 'cur'
                ndp[other] = min(
                    ndp[other],
                    dp[other] + dist(prev, cur)
                );

                // The other finger types 'cur'
                int cost = 0;

                if (other != 26)
                    cost = dist(other, cur);

                ndp[prev] = min(
                    ndp[prev],
                    dp[other] + cost
                );
            }

            dp = ndp;
            prev = cur;
        }

        return *min_element(dp.begin(), dp.end());
    }
};