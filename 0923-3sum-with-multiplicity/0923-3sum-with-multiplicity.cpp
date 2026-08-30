class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const long long MOD = 1000000007;

        long long count[101] = {};

        // Count frequency of each number
        for (int x : arr) {
            count[x]++;
        }

        long long ans = 0;

        for (int i = 0; i <= 100; i++) {
            for (int j = i; j <= 100; j++) {

                int k = target - i - j;

                if (k < j || k > 100)
                    continue;

                // Case 1: i, j, k are all different
                if (i < j && j < k) {
                    ans += count[i] * count[j] * count[k];
                }

                // Case 2: i == j != k
                else if (i == j && j < k) {
                    ans += (count[i] * (count[i] - 1) / 2) * count[k];
                }

                // Case 3: i < j == k
                else if (i < j && j == k) {
                    ans += count[i] * (count[j] * (count[j] - 1) / 2);
                }

                // Case 4: i == j == k
                else if (i == j && j == k) {
                    ans += count[i] * (count[i] - 1) * (count[i] - 2) / 6;
                }

                ans %= MOD;
            }
        }

        return ans;
    }
};