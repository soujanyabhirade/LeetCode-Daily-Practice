class Solution {
public:

    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b)
            parent[b] = a;
    }

    bool similar(string &a, string &b) {
        int diff = 0;

        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i])
                diff++;

            if (diff > 2)
                return false;
        }

        return true;
    }

    int numSimilarGroups(vector<string>& strs) {

        int n = strs.size();

        parent.resize(n);

        // Initially every string is its own group
        for (int i = 0; i < n; i++)
            parent[i] = i;

        int groups = n;

        // Compare every pair
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (similar(strs[i], strs[j])) {

                    int p1 = find(i);
                    int p2 = find(j);

                    if (p1 != p2) {
                        unite(p1, p2);
                        groups--;
                    }
                }
            }
        }

        return groups;
    }
};