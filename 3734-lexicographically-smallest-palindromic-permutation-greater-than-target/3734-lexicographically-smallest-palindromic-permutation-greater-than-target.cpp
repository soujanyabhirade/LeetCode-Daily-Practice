class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char ch : s) cnt[ch - 'a']++;

        int oddCount = 0, oddChar = -1;
        for (int c = 0; c < 26; c++) if (cnt[c] % 2 == 1) { oddCount++; oddChar = c; }
        if (n % 2 == 0 && oddCount > 0) return "";
        if (n % 2 == 1 && oddCount != 1) return "";

        int L = n / 2;
        char mid = 0;
        bool hasMid = (n % 2 == 1);
        if (hasMid) mid = 'a' + oddChar;

        vector<int> avail(26, 0);
        for (int c = 0; c < 26; c++) avail[c] = cnt[c] / 2;

        vector<int> tCode(n);
        for (int i = 0; i < n; i++) tCode[i] = target[i] - 'a';

        vector<int> work = avail;
        int Pmax = 0;
        for (int i = 0; i < L; i++) {
            int c = tCode[i];
            if (work[c] > 0) { work[c]--; Pmax++; } else break;
        }

        auto buildAscending = [&](vector<int>& counts) {
            string res;
            for (int c = 0; c < 26; c++)
                res += string(counts[c], 'a' + c);
            return res;
        };

        auto makeFull = [&](const string& H) {
            string T = H;
            if (hasMid) T += mid;
            string revH = H;
            reverse(revH.begin(), revH.end());
            T += revH;
            return T;
        };

        if (Pmax == L) {
            string H = target.substr(0, L);
            string T = makeFull(H);
            if (T > target) return T;
        }

        int startP = (Pmax == L) ? L - 1 : Pmax;
        for (int p = startP; p >= 0; p--) {
            vector<int> rem = avail;
            bool ok = true;
            for (int i = 0; i < p; i++) {
                int c = tCode[i];
                if (rem[c] > 0) rem[c]--; else { ok = false; break; }
            }
            if (!ok) continue;

            int tc = tCode[p];
            int chosen = -1;
            for (int c = tc + 1; c < 26; c++) {
                if (rem[c] > 0) { chosen = c; break; }
            }
            if (chosen == -1) continue;

            rem[chosen]--;
            string H = target.substr(0, p) + string(1, char('a' + chosen)) + buildAscending(rem);
            return makeFull(H);
        }

        return "";
    }
};