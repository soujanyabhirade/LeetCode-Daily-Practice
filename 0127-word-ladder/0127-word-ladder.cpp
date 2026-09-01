class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());

        // endWord must exist in the dictionary
        if (words.find(endWord) == words.end()) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {

            int size = q.size();

            // Process one level at a time
            for (int i = 0; i < size; i++) {

                string word = q.front();
                q.pop();

                // Try changing every character
                for (int j = 0; j < word.length(); j++) {

                    char original = word[j];

                    for (char c = 'a'; c <= 'z'; c++) {

                        if (c == original) {
                            continue;
                        }

                        word[j] = c;

                        // Reached endWord
                        if (word == endWord) {
                            return level + 1;
                        }

                        // If this word exists and hasn't been visited
                        if (words.find(word) != words.end()) {
                            q.push(word);
                            words.erase(word);
                        }
                    }

                    // Restore original character
                    word[j] = original;
                }
            }

            level++;
        }

        return 0;
    }
};