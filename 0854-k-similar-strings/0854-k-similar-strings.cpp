class Solution {
public:
    int kSimilarity(string s1, string s2) {
        if (s1 == s2)
            return 0;

        queue<string> q;
        unordered_set<string> visited;

        q.push(s1);
        visited.insert(s1);

        int swaps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string cur = q.front();
                q.pop();

                // Find the first position where cur differs from s2
                int i = 0;
                while (cur[i] == s2[i])
                    i++;

                // Try swapping i with a later position
                for (int j = i + 1; j < cur.length(); j++) {

                    // j must contain the character needed at i
                    if (cur[j] != s2[i])
                        continue;

                    // Avoid disturbing a position that is already correct
                    if (cur[j] == s2[j])
                        continue;

                    swap(cur[i], cur[j]);

                    if (cur == s2)
                        return swaps + 1;

                    if (!visited.count(cur)) {
                        visited.insert(cur);
                        q.push(cur);
                    }

                    // Restore string for next possibility
                    swap(cur[i], cur[j]);
                }
            }

            swaps++;
        }

        return -1;
    }
};