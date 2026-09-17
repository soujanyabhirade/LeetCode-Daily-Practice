class Solution {
public:
    using ll = long long;

    bool can(vector<ll>& p, int k, ll D, ll perimeter) {
        int n = p.size();

        // Duplicate the circle so we can move forward normally
        vector<ll> a(2 * n);

        for (int i = 0; i < n; i++) {
            a[i] = p[i];
            a[i + n] = p[i] + perimeter;
        }

        // nxt[i] = first point at least D away from i
        vector<int> nxt(2 * n, 2 * n);
        int j = 0;

        for (int i = 0; i < 2 * n; i++) {
            if (j < i + 1)
                j = i + 1;

            while (j < 2 * n && a[j] - a[i] < D)
                j++;

            nxt[i] = j;
        }

        // Binary lifting
        const int LOG = 6; // k <= 25

        vector<vector<int>> jump(LOG, vector<int>(2 * n));

        for (int i = 0; i < 2 * n; i++)
            jump[0][i] = nxt[i];

        for (int b = 1; b < LOG; b++) {
            for (int i = 0; i < 2 * n; i++) {
                int mid = jump[b - 1][i];

                if (mid < 2 * n)
                    jump[b][i] = jump[b - 1][mid];
                else
                    jump[b][i] = 2 * n;
            }
        }

        // Try every point as the first selected point
        for (int start = 0; start < n; start++) {
            int cur = start;
            int need = k - 1;

            // Jump k-1 times
            for (int b = 0; b < LOG; b++) {
                if (need & (1 << b)) {
                    cur = jump[b][cur];

                    if (cur >= start + n)
                        break;
                }
            }

            if (cur >= start + n)
                continue;

            // Last selected point must be at least D
            // away from the first point around the circle.
            if (a[cur] - a[start] <= perimeter - D)
                return true;
        }

        return false;
    }

    long long maxDistance(int side,
                          vector<vector<int>>& points,
                          int k) {

        ll s = side;
        ll perimeter = 4LL * s;

        vector<ll> p;

        for (auto& point : points) {
            ll x = point[0];
            ll y = point[1];

            if (y == 0) {
                // Bottom: left -> right
                p.push_back(x);
            }
            else if (x == side) {
                // Right: bottom -> top
                p.push_back(s + y);
            }
            else if (y == side) {
                // Top: right -> left
                p.push_back(3LL * s - x);
            }
            else {
                // Left: top -> bottom
                p.push_back(4LL * s - y);
            }
        }

        sort(p.begin(), p.end());

        ll low = 0;
        ll high = 2LL * s;

        while (low < high) {
            ll mid = low + (high - low + 1) / 2;

            if (can(p, k, mid, perimeter))
                low = mid;
            else
                high = mid - 1;
        }

        return low;
    }
};