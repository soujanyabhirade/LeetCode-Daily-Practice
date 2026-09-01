class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;
    unordered_set<string> words;

    void dfs(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (string p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        for (string word : wordList) {
            words.insert(word);
        }

        if (!words.count(endWord)) {
            return {};
        }

        // BFS
        unordered_map<string, int> dist;
        queue<string> q;

        q.push(beginWord);
        dist[beginWord] = 0;

        int shortest = INT_MAX;

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int d = dist[word];

            if (d >= shortest) {
                continue;
            }

            string temp = word;

            for (int i = 0; i < word.size(); i++) {
                char original = temp[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == original) continue;

                    temp[i] = c;

                    if (!words.count(temp)) {
                        continue;
                    }

                    // First time seeing this word
                    if (!dist.count(temp)) {
                        dist[temp] = d + 1;
                        q.push(temp);

                        parent[temp].push_back(word);

                        if (temp == endWord) {
                            shortest = d + 1;
                        }
                    }

                    // Another shortest way to reach this word
                    else if (dist[temp] == d + 1) {
                        parent[temp].push_back(word);
                    }
                }

                temp[i] = original;
            }
        }

        if (!dist.count(endWord)) {
            return {};
        }

        // DFS to construct all shortest paths
        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};